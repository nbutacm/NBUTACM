import pandas as pd#导入数据文件
import numpy as np#科学计算计算库
from sklearn.preprocessing import LabelEncoder#标签编码
from sklearn.preprocessing import MinMaxScaler#归一化
from sklearn.model_selection import train_test_split#数据集的划分
from sklearn.model_selection import cross_val_score, RandomizedSearchCV
from sklearn.metrics import mean_squared_error#评估函数
from sklearn.preprocessing import StandardScaler
from sklearn.svm import  LinearSVR ,SVR
from numpy import reciprocal
from random import uniform
#数据读取
train_data= pd.read_csv("d_train_20180102.csv",engine='python')
test_dataA= pd.read_csv("d_test_A_20180102.csv",engine='python')
test_labels=pd.read_csv("d_answer_a_20180128.csv",engine='python')
#数据清理
train_data.drop(['乙肝表面抗原', '乙肝表面抗体', '乙肝e抗原', '乙肝e抗体', '乙肝核心抗体', 'id', '体检日期','性别'],axis=1,inplace=True)
test_dataA.drop(['乙肝表面抗原', '乙肝表面抗体', '乙肝e抗原', '乙肝e抗体', '乙肝核心抗体', 'id', '体检日期','性别'],axis=1,inplace=True)
train_data.drop(['单核细胞%','白球比例','白蛋白','*总蛋白'],axis=1,inplace=True)
test_dataA.drop(['单核细胞%','白球比例','白蛋白','*总蛋白'],axis=1,inplace=True)
train_data.drop(['嗜碱细胞%'],axis=1,inplace=True)
test_dataA.drop(['嗜碱细胞%'],axis=1,inplace=True)
#对列的空值进行填充
for i in train_data.columns:
       train_data[i].fillna(train_data[i].mean(), inplace=True)
for i in test_dataA:
       test_dataA[i].fillna(test_dataA[i].mean(), inplace=True)
print(train_data.info())
train_data_y=train_data['血糖']
train_data.drop(['血糖'],axis=1,inplace=True)
print(test_dataA.info())
#归一化
scaler = StandardScaler()
train_data= scaler.fit_transform(train_data.astype(float))
test_dataA= scaler.transform(test_dataA.astype(float))
#建立模型
lin_svr= LinearSVR(random_state=42,max_iter=5000)
lin_svr.fit(train_data, train_data_y)
test_features_labers= lin_svr.predict(test_dataA)
#评估模型
mse= mean_squared_error(test_labels, test_features_labers)
print(mse)
print(np.sqrt(mse))
#使用RandomizedSearchCV
param_distributions = {
    'gamma': reciprocal([0.001, 0.1]),
    # 'C': uniform(1,10)
    'C': [uniform(1,10),uniform(1,10)]
}
rnd_search_cv =RandomizedSearchCV(SVR(),param_distributions,n_iter=4, verbose=2, cv=3, random_state=42)
train_bloods = pd.DataFrame(train_data_y)
rnd_search_cv.fit(train_data, train_bloods)
#预测和评估
test_features_labers = rnd_search_cv.best_estimator_.predict(test_dataA)
mse= mean_squared_error(test_labels, test_features_labers)
print(mse)
print(np.sqrt(mse))
