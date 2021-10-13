from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import r2_score
import pandas as pd
boston = datasets.load_boston()
x = boston.data
y = boston.target
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.2)
lr = LinearRegression()
lr.fit(x_train, y_train)
predict = lr.predict(x_test)

df = pd.DataFrame({'result': predict})
score = r2_score(y_test, predict)
print(score)