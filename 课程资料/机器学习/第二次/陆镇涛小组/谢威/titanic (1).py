import pandas as pd
from sklearn.feature_extraction import DictVectorizer
from sklearn.tree import DecisionTreeClassifier

# 数据加载
train_data = pd.read_csv('titanic_train.csv')
test_data = pd.read_csv('titanic_test.csv')
# 数据探索
print(train_data.info())# info() 了解数据表的基本情况：行数、列数、每列的的数据类型、数据完整度
print('-'*30)
print(train_data.describe())#describe() 了解数据表的统计情况：总数、平均值、标准差、最小值、最大值等
print('-'*30)
print(train_data.describe(include=['O']))#describe(include=[‘O’]) 查看字符串类型（非数字）的整体情况
print('-'*30)
print(train_data.head())#head 查看前几行数据（默认是前 5 行）
print('-'*30)
print(train_data.tail())#tail 查看后几行数据（默认是最后 5 行）

# 使用平均年龄来填充年龄中的 nan 值
train_data['Age'].fillna(train_data['Age'].mean(), inplace=True)
test_data['Age'].fillna(test_data['Age'].mean(),inplace=True)
# 使用票价的均值填充票价中的 nan 值
train_data['Fare'].fillna(train_data['Fare'].mean(), inplace=True)
test_data['Fare'].fillna(test_data['Fare'].mean(),inplace=True)
print(train_data['Embarked'].value_counts())
# 使用登录最多的港口来填充登录港口的 nan 值
train_data['Embarked'].fillna('S', inplace=True)
test_data['Embarked'].fillna('S',inplace=True)
# 特征选择
features = ['Pclass', 'Sex', 'Age', 'SibSp', 'Parch', 'Fare', 'Embarked']
train_features = train_data[features]
train_labels = train_data['Survived']
test_features = test_data[features]

dvec=DictVectorizer(sparse=False)
train_features=dvec.fit_transform(train_features.to_dict(orient='record'))
print(dvec.feature_names_)
['Age', 'Embarked=C', 'Embarked=Q', 'Embarked=S', 'Fare', 'Parch', 'Pclass', 'Sex=female', 'Sex=male', 'SibSp']

# 构造 ID3 决策树
clf = DecisionTreeClassifier(criterion='entropy')
# 决策树训练
clf.fit(train_features, train_labels)
test_features=dvec.transform(test_features.to_dict(orient='record'))
# 决策树预测
pred_labels = clf.predict(test_features)
# 得到决策树准确率
acc_decision_tree = round(clf.score(train_features, train_labels), 6)
print('score 准确率为: {:.2%}'.format(acc_decision_tree))