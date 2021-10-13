import pandas as pd#导入数据文件
import numpy as np#科学计算计算库
import seaborn as sns
import matplotlib.pyplot as plt#数据可视化库
import warnings
import graphviz
from sklearn import tree
import pandas_profiling as ppf#eda
from sklearn.preprocessing import LabelEncoder#标签编码
from sklearn.preprocessing import MinMaxScaler#归一化
from sklearn.model_selection import train_test_split#数据集的划分
from sklearn.tree import DecisionTreeClassifier#算法
from sklearn.metrics import mean_absolute_error#评估函数
from sklearn.metrics import r2_score
from sklearn.metrics import accuracy_score

train = pd.read_csv("train.csv") #读取文件
test = pd.read_csv("test.csv")




train.head(10)#显示数据文件的前五行
test.head()
train.info()#看数据的信息
test.info()
ppf.ProfileReport(train)##从这里要看到问题
train["Age"] = train["Age"].fillna(np.mean(train["Age"]))#填充年龄这一列的缺失值
test["Age"] = test["Age"].fillna(np.mean(test["Age"]))#测试集同理

train.drop("Cabin",axis=1,inplace=True)#删除cabin这一列然后在替代
test.drop("Cabin",axis=1,inplace=True)
train["Age"].isnull().sum()#空值的个数为0
test["Age"].isnull().sum()#空值的个数为0
train.drop("Name",axis=1,inplace=True)
test.drop("Name",axis=1,inplace=True)
train.drop("Ticket",axis=1,inplace=True)
test.drop("Ticket",axis=1,inplace=True)
train.drop("Embarked",axis=1,inplace=True)
test.drop("Embarked",axis=1,inplace=True)

train.head()
test.head()
lab = LabelEncoder()
train["Sex"] = lab.fit_transform(train["Sex"])#对sex列进行数值化
test["Sex"] = lab.fit_transform(test["Sex"])
minmax = MinMaxScaler()#实例化函数
train["Age"] = minmax.fit_transform(np.array(train["Age"]).reshape(-1,1))#归一化，是对大数值进行一个放大缩小的问题
test["Age"] = minmax.fit_transform(np.array(test["Age"]).reshape(-1,1))
train["Age"].min()
train.info()
test.head()
minmax = MinMaxScaler()
train["Fare"] = minmax.fit_transform(np.array(train["Fare"]).reshape(-1,1))
PassengerId = test.PassengerId
test["Fare"] = test["Fare"].fillna(np.mean(test["Fare"]))
test["Fare"] = minmax.fit_transform(np.array(test["Fare"]).reshape(-1,1))
x = train.drop("Survived",axis=1)
x.info()
y = train["Survived"]
y.shape
x_train,x_test,y_train,y_test = train_test_split(x,y,test_size=0.2,random_state=0)
lin = DecisionTreeClassifier(criterion='gini')#实例化算法
lin.fit(x_train,y_train)#对训练集进行拟合
y_pred = lin.predict(x_test)#对自己划分的数据集进行测试，得到的预测值
mae = mean_absolute_error(y_pred,y_test)#先不处理
predict = lin.predict(test)

# 查看准确率
train_score = lin.score(x_train,y_train)
test_score = lin.score(x_test,y_test)
print('train score:{0}; test score:{1}'.format(train_score,test_score))
dot_data = tree.export_graphviz(lin, out_file=None)
graph = graphviz.Source(dot_data)
graph.view()


def cv_score(d):
    clf = DecisionTreeClassifier(max_depth=d)
    clf.fit(x_train, y_train)
    tr_score = clf.score(x_train, y_train)
    cv_score = clf.score(x_test, y_test)
    return (tr_score, cv_score)


depths = range(2, 15)
scores = [cv_score(d) for d in depths]
tr_scores = [s[0] for s in scores]
cv_scores = [s[1] for s in scores]

# 找出交叉验证数据集评分最高的索引
best_score_index = np.argmax(cv_scores)
best_score = cv_scores[best_score_index]
best_param = depths[best_score_index]
print('best param:{0};best score:{1}'.format(best_param, best_score))


