from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
from sklearn.tree import DecisionTreeClassifier
from sklearn.datasets import load_boston

boston=load_boston()
features=boston.data
price=boston.target
train_features, test_features, train_price, test_price = train_test_split(features, price, test_size=0.33, random_state=0)
clf=DecisionTreeClassifier()
clf=clf.fit(train_features,train_price)
test_predict=clf.predict(test_features)
score=accuracy_score(test_price,test_predict)
print(score)