# -*- coding: utf-8 -*-
"""
Created on Wed Oct 14 19:13:11 2020

@author: cpx
"""

import numpy as np
import pandas as pd
from sklearn.feature_extraction import DictVectorizer
from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import cross_val_score
from sklearn import tree
import graphviz


 
train_data = pd.read_csv('titanic_train.csv')  #加载数据
test_data = pd.read_csv('titanic_test.csv')
train_data['Age'].fillna(train_data['Age'].mean(),inplace = True)#Age中的空值用平均年龄来填充

train_data['Embarked'].fillna('S',inplace = True)#到港口为“S”类型的占比最高，把缺失的港口用“S”港口填充
test_data['Age'].fillna(test_data['Age'].mean(),inplace = True)#Age中的空值可用平均年龄来填充
test_data['Fare'].fillna(test_data['Fare'].mean(),inplace = True)#Fare中的空值可用平均票价来填充

#Cabin有大量的缺失值，在训练集和测试集中缺失率都比较高，无法补齐

'''
通过数据探索，发现PassengerId和Name对分类没有太大作用；
Cabin有大量的缺失值，可以放弃；Ticket字段编码较乱，没有太大作用。
其余字段可能和预测乘客的生存情况有关，通过分类器来处理。
'''

features = ['Pclass','Sex','Age','SibSp','Parch','Fare','Embarked']
train_features = train_data[features]
train_labels = train_data['Survived']
test_features = test_data[features]

dv = DictVectorizer(sparse = False)
train_features = dv.fit_transform(train_features.to_dict(orient= 'record'))

#使用ID3算法 构造决策树
clf = DecisionTreeClassifier(criterion = 'entropy')
clf.fit(train_features, train_labels)


test_features = dv.transform(test_features.to_dict(orient= 'record'))
pred_labels = clf.predict(test_features)
#测试集中并没有真实的生存状况的结果，只能使用训练集中的数据进行模型评估
#用K折交叉验证统计决策树分类器的准确率
print('准确率：', np.mean(cross_val_score(clf,train_features, train_labels,cv=4)))

dot_data = tree.export_graphviz(clf, out_file=None)
graph = graphviz.Source(dot_data)
graph.view()