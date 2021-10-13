# -*- coding: utf-8 -*-
"""
Created on Sat Apr 25 14:57:54 2020

@author: YZX
"""
import numpy as np
from sklearn.datasets import fetch_lfw_people
import matplotlib.pyplot as plt


lfw_people = fetch_lfw_people(resize = 1)
print(lfw_people.keys())
# 输出：dict_keys(['data', 'images', 'target', 'target_names', 'DESCR'])
 
print(lfw_people.data.shape)
 
print(lfw_people.images.shape)

# 对数据集faces.data 做乱序处理
random_indexes = np.random.permutation(len(lfw_people.data))
X = lfw_people.data[random_indexes]
 
example_faces = X[:36]
example_faces.shape

def plot_faces(faces):
 
    fig, axes = plt.subplots(6, 6, figsize=(10, 10),
                            subplot_kw={'xticks':[], 'yticks':[]},
                            gridspec_kw=dict(hspace=0.1, wspace=0.1))
    for i, ax in enumerate(axes.flat):
        ax.imshow(faces[i].reshape(62,47), cmap='bone')
 
    plt.show()
 
plot_faces(example_faces)

