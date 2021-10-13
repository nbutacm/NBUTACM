import numpy as np
from keras.layers.core import Dense, Activation, Dropout
from keras.layers import LSTM
from keras.models import Sequential, load_model
from keras.callbacks import Callback
import keras.backend.tensorflow_backend as KTF
import tensorflow as tf
import pandas as pd
import os
import keras.callbacks
import matplotlib.pyplot as plt

# 设定为自增长
os.environ['CUDA_VISIBLE_DEVICES'] = '0'
config = tf.ConfigProto()
config.gpu_options.allow_growth = True
session = tf.Session(config=config)
KTF.set_session(session)


def NormalizeMult(data, normalize):
    print(normalize)
    for i in range(0, data.shape[1]):

        listlow = normalize[i, 0]
        listhigh = normalize[i, 0]
        delta = listhigh - listlow

        if delta != 0:
            for j in range(0, data.shape[0]):
                data[j, i] = (data[j, i] - listlow) / delta

    return data, normalize


def trainModel(train_X, train_Y):
    '''
    trainX，trainY: 训练LSTM模型所需要的数据
    '''
    model = Sequential()  # 定义一个堆叠的顺序模型
    model.add(LSTM(
        240,
        input_shape=(train_X.shape[1], train_X.shape[2]),
        return_sequences=True))
    model.add(Dropout(0.3))

    model.add(LSTM(
        240,
        return_sequences=True))
    model.add(Dropout(0.3))

    model.add(LSTM(
        240,
        return_sequences=False))  # 返回维度为 240 的单个向量
    model.add(Dropout(0.3))

    model.add(Dense(
        train_Y.shape[1]))
    model.add(Activation("relu"))

    model.compile(loss='mse', optimizer='adam', metrics=['acc'])  # 配置模型学习过程

    model.fit(train_X, train_Y, epochs=100, batch_size=64, verbose=1, validation_data=(test_X, test_Y))
    model.summary()

    return model


if __name__ == "__main__":
    train_num = 6
    per_num = 1
    # set_range = False
    set_range = True
    series_idx = ['lat', 'lon', 'altitude']
    # 读入时间序列的文件数据
    data = pd.read_csv('20081213052002.txt', sep=',').loc[:, series_idx].values
    print("样本数：{0}，维度：{1}".format(data.shape[0], data.shape[1]))
    # print(data)

    # 画样本数据库
    plt.scatter(data[:, 1], data[:, 0], c='b', marker='o', label='traj_A')
    plt.legend(loc='upper left')
    plt.grid()
    plt.show()

    # 归一化
    data, normalize = NormalizeMult(data, set_range)
    # print(normalize)

    # 生成训练数据
    train_X, train_Y, test_X, test_Y = create_dataset(data, train_num, per_num)
    print("x\n", train_X.shape)
    print("y\n", train_Y.shape)

    # 训练模型
    model = trainModel(train_X, train_Y)
    loss, acc = model.evaluate(train_X, train_Y, verbose=2)
    print('Loss : {}, Accuracy: {}'.format(loss, acc * 100))

    # 保存模型
    np.save("./traj_model_trueNorm.npy", normalize)
    model.save("./traj_model_240_3layers_altitude.h5")