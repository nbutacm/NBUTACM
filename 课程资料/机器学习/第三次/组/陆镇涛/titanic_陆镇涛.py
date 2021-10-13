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
from sklearn.svm import SVC
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
classifier = SVC(C=2, kernel='rbf', gamma=10, decision_function_shape='ovo')
classifier.fit(x_train,y_train)
tra_label = classifier.predict(x_train)#训练集的预测标签
tes_label = classifier.predict(x_test)#测试集的预测标签
print("训练集：",accuracy_score(y_train, tra_label))
print("测试集：",accuracy_score(y_test, tes_label))




