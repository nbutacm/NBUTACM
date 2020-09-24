#!/bin/bash
g++ id_BST.cpp -o id_BST.out -O2 -std=c++11
g++ id_list.cpp -o id_list.out -O2 -std=c++11
./id_BST.out
./id_list.out

(cat list_find.txt BST_find.txt) | while read line
do
    echo $line
done
