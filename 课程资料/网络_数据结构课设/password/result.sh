#!/bin/bash
g++ password_BST.cpp -o execute/password_BST.out -std=c++11 -O2
execute/password_BST.out
g++ password_Hash.cpp -o execute/password_Hash.out -std=c++11 -O2
execute/password_Hash.out

(cat result_time/password_BST_result.txt result_time/password_Hash_result.txt) | while read line
do
    echo $line
done
