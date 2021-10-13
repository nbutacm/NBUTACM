import numpy as np
import pandas as pd
from sklearn.linear_model import LogisticRegression
from sklearn import metrics
from sklearn import model_selection
from sklearn.svm import SVC,LinearSVC
from matplotlib import pyplot as plt
#matplotlib inline
#数据读取和处理
train_src=pd.read_csv('titanic_train.csv')

train=train_src[['Survived','Pclass','Sex', 
                'Age','SibSp','Parch','Fare']]             #筛选六个变量作为预测变量(特征)
train['Sex']=train['Sex'].replace({'male':1,'female':0})   #把Sex变量的取值male替换为1，female替换为0

age_mean=train['Age'].mean()                               #有117个乘客Age有缺失，用平均年龄替换
train['Age']=train['Age'].fillna(age_mean) 
#拆分出自变量X，目标变量y
train_X=train.ix[:,1:]                                     #训练集自变量
train_y=train['Survived']                                  #训练集因变量 

X_train,X_test,y_train,y_test = model_selection.\
                                train_test_split(train_X,train_y,test_size=0.3,random_state=42)   #随机种子数 
lr = LogisticRegression()
lr.fit(X_train,y_train) 

#训练集的预测准确率 
y_train_pre=lr.predict(X_train)                #对训练集进行预测
metrics.accuracy_score(y_train,y_train_pre)    #训练集准确率 

#使用测试集验证模型 
y_test_pre=lr.predict(X_test)                  #对测试集进行预测
metrics.accuracy_score(y_test,y_test_pre)      #测试集准确率
def classifier_func(X_train,y_train,X_test,y_test): 
    #SVM
    svc=SVC()
    svc.fit(X_train,y_train)
    SVM_training = svc.score(X_train,y_train) 
    SVM_testing = svc.score(X_test,y_test) 
    SVM_error_matrix = abs(SVM_training-SVM_testing) 
    print("SVM  ：训练准确率:{}，预测准确率:{}，残差:{}".format(SVM_training,SVM_testing,SVM_error_matrix))
    return

classifier_func(X_train,y_train,X_test,y_test)
