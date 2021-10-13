import random
import pandas as pd
import numpy as np
from sklearn.preprocessing import LabelEncoder, StandardScaler  # 标签编码
from sklearn.model_selection import cross_val_score, RandomizedSearchCV, train_test_split  # k折交叉验证
from sklearn.svm import SVC
from sklearn.metrics import accuracy_score
train_data = pd.read_csv('titanic_train.csv')
test_data = pd.read_csv('titanic_test.csv')
# 数据分析
# print(test_data.info())#训练集信息

train_data['Age'].fillna(train_data['Age'].mean(), inplace=True)
train_data['Fare'].fillna(train_data['Fare'].mean(), inplace=True)
train_data['Embarked'].fillna('S', inplace=True)
#数据清洗结束，进行特征提取
feature = ['Pclass', 'Sex', 'Age', 'SibSp', 'Parch', 'Fare', 'Embarked']
train_feature = train_data[feature]
train_survived = train_data['Survived']

#观看feature信息并处理
# print(train_feature.info())#观看feature信息
encoder = LabelEncoder()
train_feature['Sex'] = encoder.fit_transform(train_feature['Sex'])
train_feature['Embarked'] = encoder.fit_transform(train_feature['Embarked'])
print(train_feature.info())#观看修改过后的feature信息

#归一化
scaler = StandardScaler()
train_feature.astype(float)
X_train_scaled = scaler.fit_transform(train_feature)#均值归一化
feature_train, feature_test, survived_train, survived_test = train_test_split(X_train_scaled, train_survived, test_size=0.3, random_state=0)#划分测试集与训练集
classifier = SVC(C=2, kernel='rbf', gamma=10, decision_function_shape='ovo')
classifier.fit(feature_train,survived_train)
tra_label = classifier.predict(feature_train)#训练集的预测标签
tes_label = classifier.predict(feature_test)#测试集的预测标签
print("训练集：",accuracy_score(survived_train, tra_label))
print("测试集：",accuracy_score(survived_test, tes_label))
