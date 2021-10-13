import numpy as np
import PIL.Image as image
from sklearn.cluster import KMeans
from sklearn import preprocessing

# 加载图像，并对数据进行规范化
def load_data(filePath):
    f = open(filePath,'rb')
    data = []
    # 得到图像的像素值
    img = image.open(f)
    # 得到图像尺寸
    width, height = img.size
    for x in range(width):
        for y in range(height):
            # 得到点(x,y)的三个通道值
            c1, c2, c3 = img.getpixel((x, y))
            data.append([c1, c2, c3])
    f.close()
    # 采用Min-Max规范化
    mm = preprocessing.MinMaxScaler()
    data = mm.fit_transform(data)
    return np.mat(data), width, height
def printimg():
    for x in range(width):
        for y in range(height):
            # 根据类别设置图像灰度, 类别0 灰度值为255（白）， 类别1 灰度值为0（黑）
            pic_bin.putpixel((x, y), int(255 * (label[x][y])))
    pic_bin.save("12_bin.jpg", "JPEG")
# 加载图像，得到规范化的结果img，以及图像尺寸
img, width, height = load_data('./12.jpg')
# 用K-Means对图像进行2聚类
kmeans =KMeans(n_clusters=2)
kmeans.fit(img)
label = kmeans.predict(img)
# 将图像聚类结果，转化成图像尺寸的矩阵
label = label.reshape([width, height])
# 创建个新图像pic_bin,保存图像聚类的结果，并设置为0或255（黑白）
pic_bin = image.new("L", (width, height))#L为灰度显示
printimg()


