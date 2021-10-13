
import random
import pandas as pd
import numpy as np
from sklearn.preprocessing import LabelEncoder, StandardScaler  # 标签编码
from sklearn.model_selection import cross_val_score, RandomizedSearchCV  # k折交叉验证
from sklearn.svm import SVC, LinearSVR, SVR
from sklearn.metrics import accuracy_score, mean_squared_error
from numpy import reciprocal
from random import uniform

def main():
    # 数据加载
    train_data = pd.read_csv('d_train_20180102.csv', encoding='GBK')
    train_bloods = train_data['血糖'].astype(float)
    test_data = pd.read_csv('d_test_A_20180102.csv', encoding='GBK')
    test_bloods = pd.read_csv('d_answer_a_20180128.csv', encoding='GBK').astype(float)
    train_data = train_data.drop(['id', '体检日期'], axis=1)
    test_data = test_data.drop(['id', '体检日期'], axis=1)
    train_data = train_data.drop(['乙肝表面抗原', '乙肝表面抗体', '乙肝e抗原', '乙肝e抗体', '乙肝核心抗体', '血糖'], axis=1)
    test_data = test_data.drop(['乙肝表面抗原', '乙肝表面抗体', '乙肝e抗原', '乙肝e抗体', '乙肝核心抗体'], axis=1)

    label = train_data.columns
    encoder = LabelEncoder()
    train_data['性别'] = encoder.fit_transform(train_data['性别'])
    test_data['性别'] = encoder.fit_transform(test_data['性别'])
    train_data.astype(float)
    test_data.astype(float)
    for i in label:
        train_data[i].fillna(train_data[i].mean(), inplace=True)
        test_data[i].fillna(test_data[i].mean(), inplace=True)

    scaler = StandardScaler()
    train_data = pd.DataFrame(scaler.fit_transform(train_data))  # 均值归一化
    test_data = pd.DataFrame(scaler.fit_transform(test_data))  # 均值归一化/

    # 回归得用线性svr
    lin_svr = LinearSVR(random_state=42)
    lin_svr.fit(train_data, train_bloods)
    predict_bloods = lin_svr.predict(test_data)
    mse = mean_squared_error(test_bloods, predict_bloods)
    print(mse)
    print(np.sqrt(mse))
    param_distributions = {
        'gamma': reciprocal([0.001, 0.1]),
        # 'C': uniform(1,10)
        'C': [uniform(1, 10), uniform(10, 1)]
    }
    rnd_search_cv = RandomizedSearchCV(SVR(), param_distributions, n_iter=4, verbose=2, cv=3, random_state=42)
    train_bloods = pd.DataFrame(train_bloods)
    rnd_search_cv.fit(train_data, train_bloods)
    y_pred = rnd_search_cv.best_estimator_.predict(train_data)
    mse = mean_squared_error(train_bloods, y_pred)
    print(np.sqrt(mse))  # 0.5727524770785356
    y_pred = rnd_search_cv.best_estimator_.predict(test_data)
    mse = mean_squared_error(test_bloods, y_pred)
    print(np.sqrt(mse))  # 0.592916838552874



if __name__=='__main__':
    main()
