from sklearn.cluster import KMeans
from sklearn import preprocessing
import pandas as pd

# 输入数据
data = pd.read_csv('wine_Kmeans.data', delimiter=',')
train_x = data[["k1","k2","k3","k4","k5","k6","k7","k8","k9","k10","k11","k12","k13"]]
df = pd.DataFrame(train_x)
kmeans = KMeans(n_clusters=3)#随机选取3种酒
# 规范化到[0,1]空间
min_max_scaler=preprocessing.MinMaxScaler()
train_x=min_max_scaler.fit_transform(train_x)
# kmeans算法
kmeans.fit(train_x)
predict_y = kmeans.predict(train_x)
# 合并聚类结果，插入到原数据中
result = pd.concat((data,pd.DataFrame(predict_y)),axis=1)
result.rename({0:u'聚类'},axis=1,inplace=True)
print(result)
