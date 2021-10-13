import numpy as np


class SVM:
    def __init__(self, x_data, y_data, epsilon=0.001, c=None, algo='smo'):
        # all the notations follow Li Hang's book
        self._x_data = x_data # feature 数据
        self._y_data = y_data # label 数据
        self._a = np.array([1.]*len(self._x_data)) # dont forget to set the param to be float type
        self._b = 0.0 # 待求变量
        self._w = None # 待求变量
        self._K = self._cal_kernel() # xi^T xj, 是一个方阵
        self._E = self._cal_E() # Ei = f(xi)-yi，是一个list
        self._epsilon = epsilon # 精度误差
        self._c = c # for soft margin
        self._algo = algo # 目前只有smo算法供选

    # 对外接口
    def train(self):
        self._smo()

    # 对外接口，获取训练后的模型参数
    def model(self):
        self._w = np.matmul((self._a*self._y_data).reshape(1, (len(self._a))), self._x_data)  # get a vecotr
        return self._w, self._b

    # smo算法的总体逻辑
    def _smo(self):
        counter = 100
        while 1:
            id_a1, id_a2 = self._choose_a()
            self._update(id_a1, id_a2)
            if self._satisfy() or counter == 0:
                break
            counter -= 1

    # 选择 a1，a2
    def _choose_a(self):
        a1_id, a2_id = None, None
        on_bound_id = []
        remain_id = []
        # 筛选出 support vector 和 非support vector
        for i in range(len(self._a)):
            if self._a[i] > 0 and (self._c is None or self._a[i] < self._c):
                on_bound_id.append(i)
            else:
                remain_id.append(i)
        # 正式开始找 a1，a2
        for i in on_bound_id:
            # 找不满足KKT条件的"伪support vector"，作为a1
            if not(1-self._epsilon <= self._y_data[i] * self._g(i) <= 1+self._epsilon):
                # 基于上述的a1，寻找a2
                a2_id = self._choose_a2(i, on_bound_id, remain_id)
                if a2_id is not None:
                    a1_id = i
                    return a1_id, a2_id
        # 如果所有support vector 都找遍了，就只能找其它数据点作为a1
        for i in remain_id:
            if self._a[i] == 0:
                if not(1-self._epsilon <= self._y_data[i] * self._g(i)):
                    a2_id = self._choose_a2(i, on_bound_id, remain_id)
                    if a2_id is not None:
                        a1_id = i
                        return a1_id, a2_id
            elif self._c is not None and self._a[i] == self._c: # soft margin 才会通过这一步
                if not(self._y_data[i] * self._g(i) <= 1+self._epsilon):
                    a2_id = self._choose_a2(i, on_bound_id, remain_id)
                    if a2_id is not None:
                        a1_id = i
                        return a1_id, a2_id
        return a1_id, a2_id

    # 筛选a2
    def _choose_a2(self, a1_id, on_bound_id, remain_id):
        a2_id = None
        E1 = self._E[a1_id]

        # 第一步：比较E1, E2,并检查是否有足够的更新
        if E1 > 0:
            tmp = np.argmin(self._E)
        elif E1 <= 0:
            tmp = np.argmax(self._E)
        if tmp != a1_id and self._check_enough_diff(a1_id, tmp):
            a2_id = tmp
            return a2_id
        else:
            # 第二步：若第一步没有足够的更新，则找伪"support vector"
            for id in on_bound_id:
                if id != a1_id and self._check_enough_diff(a1_id, id):
                    a2_id = id
                    return a2_id
            # 第三步：若第二步仍没有足够的更新，则找剩下的点
            for id in remain_id:
                if id != a1_id and self._check_enough_diff(a1_id, id):
                    a2_id = id
                    return a2_id
        return a2_id

    # 检验是否满足KKT条件
    def _satisfy(self):
        # check sum of a times y
        # 拉格朗日函数对b求偏导得到的式子
        if not (-self._epsilon <= np.dot(self._a, self._y_data) <= self._epsilon):
            return False

        if self._c is not None:
            # soft margin
            # check range of a
            for a in self._a:
                if not (0 <= a <= self._c+self._epsilon):
                    return False
            # check y times g
            for i in range(len(self._y_data)):
                yg = self._y_data[i] * self._g(i)
                if yg >= 1:
                    if not (0 <= self._a[i] <= self._epsilon):
                        return False
                elif yg == 1:
                    if not (0 < self._a[i] < self._c + self._epsilon):
                        return False
                else:
                    if not (self._c - self._epsilon <= self._a[i] <= self._c + self._epsilon):
                        return False
        else:
            # hard margin
            for i in range(len(self._a)):
                if self._a[i] < 0: # dual feasbility
                    return False
                elif self._a[i] > 0 and not (1-self._epsilon <= self._y_data[i]*self._g(i) <= 1+self._epsilon): # not satisfied complementary slackness
                    return False
                elif self._a[i] == 0 and self._y_data[i]*self._g(i) <= 1-self._epsilon: # not satisfied complementary slackness
                    return False
        return True

    # 更新 a1，a2 到 a的list中
    def _update(self, id1, id2):
        # update a2
        k11 = self._K[id1][id1]
        k22 = self._K[id2][id2]
        k12 = self._K[id1][id2]

        a2_old = self._a[id2]
        a1_old = self._a[id1]
        y2 = self._y_data[id2]
        y1 = self._y_data[id1]
        E1_old = self._E[id1]
        E2_old = self._E[id2]
        b_old  = self._b

        eta = k11 + k22 - 2 * k12
        a2 = a2_old + y2 * (E1_old - E2_old) / eta # a2 更新的式子
        a2 = self.clip_a2(a2, id1, id2)            # 和可行域比较，得出最终的a2
        # update a1
        a1 = a1_old + y1*y2 * (a2_old-a2)          # a1 更新的式子

        # update b
        b1_new = -E1_old - y1*k11 * (a1-a1_old) - y2*k12 * (a2-a2_old) + b_old
        b2_new = -E2_old - y1*k12 * (a1-a1_old) - y2*k22 * (a2-a2_old) + b_old
        self._b = (b1_new+b2_new)/2
        self._a[id1], self._a[id2] = a1, a2

        # update E
        self._update_E()                           # 更新E的列表

    def _check_enough_diff(self, id1, id2):
        k11 = self._K[id1][id1]
        k22 = self._K[id2][id2]
        k12 = self._K[id1][id2]

        a2_old = self._a[id2]
        y2 = self._y_data[id2]
        E1_old = self._E[id1]
        E2_old = self._E[id2]

        eta = k11 + k22 - 2 * k12
        a2 = a2_old + y2 * (E1_old - E2_old) / eta
        a2 = self.clip_a2(a2, id1, id2)

        # 检查更新量是否够大，直接使用精度检测的epsilon，其实也可以自行设置另外的值
        if abs(a2-a2_old) > self._epsilon:
            return True
        return False

    # 和可行域比较
    def clip_a2(self, a2, id1, id2):
        L, H = None, None
        if self._y_data[id1] == self._y_data[id2]:
            if self._c is not None:
                L = max(0, self._a[id2]+self._a[id1] - self._c)
                H = min(self._c, self._a[id2]+self._a[id1])
            else:
                L = 0
                H = self._a[id2]+self._a[id1]
        else:
            L = max(0, self._a[id2]-self._a[id1])
            if self._c is not None:
                H = min(self._c, self._c + self._a[id2]-self._a[id1])
        if a2 < L:
            cliped_a2  = L
        else:
            if H is None:
                cliped_a2 = a2
            elif a2 <= H:
                cliped_a2 = a2
            else:
                cliped_a2 = H
        return cliped_a2

    # g(x)对应的是课件中的f(x)
    def _g(self, index):
        return np.sum(self._a * self._y_data * self._K[index])+self._b

    # 计算方阵 K
    def _cal_kernel(self):
        return np.matmul(self._x_data, self._x_data.transpose())

    # 计算列表 E
    def _cal_E(self):
        tmp = []
        for i in range(len(self._y_data)):
            tmp.append(self._g(i)-self._y_data[i])
        return np.array(tmp)

    # 更新列表 E
    def _update_E(self):
        self._E = self._cal_E()


if __name__ =="__main__":
    X = np.array([[-3.,1.],[-2.,1.],[-1.,1.],[1.,1.],[2.,-1.],[3.,-1.]])
    y = np.array([-1,-1,-1,1,1,1])
    svm_model = SVM(X, y)
    svm_model.train()
    w, b = svm_model.model()
    print("w = ", w, "b = ", b)

