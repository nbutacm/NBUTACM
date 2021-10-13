import csv
import os
import pandas as pd
from sklearn import svm


def readData(fileName):
    result = {}
    with open(fileName, 'rb') as f:
        rows = csv.reader(f)
        for row in rows:
            if result.has_key('attr_list'):
                for i in range(len(result['attr_list'])):
                    key = result['attr_list'][i]
                    if not result.has_key(key):
                        result[key] = []
                    result[key].append(row[i])
            else:
                result['attr_list'] = row
    return result


def writeData(fileName, data):
    csvFile = open(fileName, 'w')
    writer = csv.writer(csvFile)
    n = len(data)
    for i in range(n):
        writer.writerow(data[i])
    csvFile.close()


def convertData(dataList):
    hashTable = {}
    count = 0.0
    for i in range(len(dataList)):
        if not hashTable.has_key(dataList[i]):
            hashTable[dataList[i]] = count
            count += 1
        dataList[i] = hashTable[dataList[i]]


def convertValueData(dataList):
    sumValue = 0.0
    count = 0
    for i in range(len(dataList)):
        if dataList[i] == "":
            continue
        sumValue += float(dataList[i])
        count += 1
        dataList[i] = float(dataList[i])
    avg = sumValue / count
    for i in range(len(dataList)):
        if dataList[i] == "":
            dataList[i] = avg


def dataPredeal(data):
    convertValueData(data["Age"])
    convertData(data["Fare"])
    convertData(data["Pclass"])
    convertData(data["Sex"])
    convertData(data["SibSp"])
    convertData(data["Parch"])
    convertData(data["Embarked"])


def getX(data):
    x = []
    ignores = {"PassengerId": 1, "Survived": 1, "Name": 1, "Ticket": 1, "Cabin": 1, "Fare": 1, "Embarked": 1}
    for i in range(len(data["PassengerId"])):
        x.append([])
        for j in range(len(data["attr_list"])):
            key = data["attr_list"][j]
            if not ignores.has_key(key):
                x[i].append(data[key][i])
    return x


def getLabel(data):
    label = []
    for i in range(len(data["PassengerId"])):
        label.append(int(data["Survived"][i]))
    return label


def calResult(x, label, input_x):
    svmcal = svm.SVC(kernel='linear').fit(x, label)
    return svmcal.predict(input_x)


def run():
    data = readData('titanic_train.csv')
    test_data = readData('titanic_test.csv')
    dataPredeal(data)
    dataPredeal(test_data)
    x = getX(data)
    label = getLabel(data)
    input_x = getX(test_data)
    x_result = calResult(x, label, input_x)
    res = [[test_data["PassengerId"][i], x_result[i]] for i in range(len(x_result))]
    res.insert(0, ["PassengerId", "Survived"])
    writeData('result.csv', res)


run()