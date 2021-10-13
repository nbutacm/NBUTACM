
import pandas as pd#导入数据文件
import numpy as np#科学计算计算库
import seaborn as sns
import matplotlib.pyplot as plt#数据可视化库
import warnings
import pandas_profiling as ppf#eda
from sklearn.preprocessing import LabelEncoder#标签编码
from sklearn.preprocessing import MinMaxScaler#归一化
from sklearn.model_selection import train_test_split#数据集的划分
from sklearn.linear_model import LinearRegression#算法
from sklearn.metrics import mean_absolute_error#评估函数

train = pd.read_csv("data/train.csv")
test = pd.read_csv("data/test.csv")

train.head(10)#显示数据文件的前五行
test.head()
train.info()#看数据的信息
test.info()
ppf.ProfileReport(train)##从这里要看到问题

#缺省值处理
train["Age"] = train["Age"].fillna(np.mean(train["Age"]))#填充年龄这一列的缺失值
test["Age"] = test["Age"].fillna(np.mean(test["Age"]))#同步进行

train.drop("Cabin",axis=1,inplace=True)#删除cabin这一列然后在替代

test.drop("Cabin",axis=1,inplace=True)
train["Age"].isnull().sum()#空值的个数为0
test["Age"].isnull().sum()#空值的个数为0

#删除没必要的列
train.drop("Name",axis=1,inplace=True)
test.drop("Name",axis=1,inplace=True)
train.drop("Ticket",axis=1,inplace=True)
test.drop("Ticket",axis=1,inplace=True)
train.drop("Embarked",axis=1,inplace=True)
test.drop("Embarked",axis=1,inplace=True)

train.head()
test.head()

#编码--将字符串做成数值型
lab = LabelEncoder()
train["Sex"] = lab.fit_transform(train["Sex"])#对sex列进行数值化
test["Sex"] = lab.fit_transform(test["Sex"])
minmax = MinMaxScaler()#实例化函数
train["Age"] = minmax.fit_transform(np.array(train["Age"]).reshape(-1,1))#归一化，是对大数值进行一个放大缩小的问题
test["Age"] = minmax.fit_transform(np.array(test["Age"]).reshape(-1,1))
train["Age"].min()

#查看改变之后的数据
train.info()
test.head()

#对数据进行处理
minmax = MinMaxScaler()
train["Fare"] = minmax.fit_transform(np.array(train["Fare"]).reshape(-1,1))
train.info()
PassengerId = test.PassengerId
test["Fare"] = test["Fare"].fillna(np.mean(test["Fare"]))
test["Fare"] = minmax.fit_transform(np.array(test["Fare"]).reshape(-1,1))

#划分数据集--训练集和测试集
x = train.drop("Survived",axis=1)
x.info()
y = train["Survived"]
y.shape
x_train,x_test,y_train,y_test = train_test_split(x,y,test_size=0.2,random_state=0)#划分数据集
x_train.shape,y_train.shape#检查一下shape

#使用sklearn来搭建模型-训练
lin = LinearRegression()#实例化算法
lin.fit(x_train,y_train)#对训练集进行拟合
y_pred = lin.predict(x_test)#对自己划分的数据集进行测试，得到的预测值
mae = mean_absolute_error(y_pred,y_test)#先不处理
mae
predict = lin.predict(test)
predict##Survived的值

submission = pd.DataFrame({'PassengerId': PassengerId, 'Survived': predict})#以字典的形式来建立dataframe
submission.to_csv("submission1.csv",index = False)#转换成csv文件
#pd.read_csv("submission.csv")

