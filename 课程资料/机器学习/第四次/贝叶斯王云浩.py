import os
import jieba
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.naive_bayes import MultinomialNB
from sklearn import metrics
#定义读取文件的函数
def my_get_data(base_path, labels):
    contents = []
    # 数据在文件夹下，需要遍历各个文档类别下的文件
    for label in labels:
        files = {fileName for fileName in os.listdir(base_path + label)}
        for fileName in files:
            file = open(base_path + label + '/' + fileName, encoding='gb18030')
            word = jieba.cut(file.read())
            contents.append(' '.join(word))
    return contents
#三个文件的路径
stopword_base_path = 'stop/stopword.txt'
train_base_path = 'train/'
test_base_path = 'test/'
#标签
train_labels = ['女性', '体育', '文学', '校园']
test_labels = ['女性', '体育', '文学', '校园']
# 获取训练集
train_contents = my_get_data(train_base_path, train_labels)
# 获取测试集
test_contents = my_get_data(test_base_path, test_labels)
stop_words = [line.strip() for line in open(stopword_base_path, encoding='utf-8-sig').readlines()]
tf = TfidfVectorizer(stop_words=stop_words, max_df=0.5)
train_features = tf.fit_transform(train_contents)  # 拟合
# 生成多项式贝叶斯分类器
train_labels = ['体育'] * 1337 + ['女性'] * 954 + ['文学'] * 766 + ['校园'] * 249
clf = MultinomialNB(alpha=0.001).fit(train_features, train_labels)  # MultinomialNB.fit(x,y) 其中 y的数量要等于训练x的数量
# 使用生成的分类器做预测
test_tf = TfidfVectorizer(stop_words=stop_words, max_df=0.5, vocabulary=tf.vocabulary_)
test_features = test_tf.fit_transform(test_contents)
# 将所得的模型用于测试集里进行预测
predicted_labels = clf.predict(test_features)
# 评估模型
test_labels = ['体育'] * 115 + ['女性'] * 38 + ['文学'] * 31 + ['校园'] * 16
#输出准确率
print('这个模型的准确率为', metrics.accuracy_score(test_labels, predicted_labels))

