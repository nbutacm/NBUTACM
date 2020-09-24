#include <bits/stdc++.h>
#include "../../Sorter.hpp"

using namespace std;
int const NUMS = 20;

struct node {
    string pasd;
    int val;
    node(const string &s = "", const int &val = 0) : pasd(s), val(val) { }
    bool operator<(const node & obj) const {
        return val < obj.val;
    }
    int operator/(const int &x) const {
        return this->val / x;
    } 
};
char p[50];

void show(vector<node>& v, int nums, ofstream &out) {
    for (int i = 0; i < 20; i++) {
        out << v[i].pasd << "\t" << v[i].val << endl;
    }
}

void test_Shell(vector<node> v) {
    ofstream out("shellSort.txt");
    clock_t startTime = clock();
    Sorter<node, vector<node>&>::shellSort(v, 0, v.size() - 1, false);
    clock_t endTime = clock();
    double result = (double)(endTime - startTime);
    show(v, NUMS, out);
    out << "The Time is : "  << fixed << setprecision(6) << result / CLOCKS_PER_SEC << "s" << endl;
    out.close();
}

void test_quickSort(vector<node> v) {
    ofstream out("quickSort.txt");
    clock_t startTime = clock();
    Sorter<node, vector<node>&>::quickSort(v, 0, v.size() - 1, false);
    clock_t endTime = clock();
    double result = (double)(endTime - startTime);
    show(v, NUMS, out);
    out << "The Time is : "  << fixed << setprecision(6) << result / CLOCKS_PER_SEC << "s" << endl;
    out.close();
}

void test_merageSort(vector<node> v) {
    ofstream out("merageSort.txt");
    clock_t startTime = clock();

    vector<node> temp(v.size());
    Sorter<node, vector<node>&>::MergeSort(v, temp, 0, v.size() - 1, false);

    clock_t endTime = clock();
    double result = (double)(endTime - startTime);
    show(v, NUMS, out);
    out << "The Time is : "  << fixed << setprecision(6) << result / CLOCKS_PER_SEC << "s" << endl;
    out.close();
}

void test_HeapSort(vector<node> v) {
    ofstream out("heapSort.txt");
    clock_t startTime = clock();

    vector<node> temp(v.size());
    Sorter<node, vector<node>&>::HeapSort(v, v.size(), false);

    clock_t endTime = clock();
    double result = (double)(endTime - startTime);
    show(v, NUMS, out);
    out << "The Time is : "  << fixed << setprecision(6) << result / CLOCKS_PER_SEC << "s" << endl;
    out.close();
}

void test_RadixSort(vector<node> v) {
    ofstream out("radixSort.txt");
    clock_t startTime = clock();

    vector<node> temp(v.size());
    Sorter<node, vector<node>&>::RadixSort(v, v.size(), false);

    clock_t endTime = clock();
    double result = (double)(endTime - startTime);
    show(v, NUMS, out);
    out << "The Time is : "  << fixed << setprecision(6) << result / CLOCKS_PER_SEC << "s" << endl;
    out.close();
}

void test_insertSorter(vector<node> v) {
    ofstream out("insertSorter.txt");
    clock_t startTime = clock();

    vector<node> temp(v.size());
    Sorter<node, vector<node>&>::InsertionSorter(v, v.size(), false);

    clock_t endTime = clock();
    double result = (double)(endTime - startTime);
    show(v, NUMS, out);
    out << "The Time is : "  << fixed << setprecision(6) << result / CLOCKS_PER_SEC << "s" << endl;
    out.close();
}

void test_bullbleSort(vector<node> v) {
    ofstream out("bullbleSort.txt");
    clock_t startTime = clock();

    vector<node> temp(v.size());
    Sorter<node, vector<node>&>::BullbleSort(v, v.size(), false);

    clock_t endTime = clock();
    double result = (double)(endTime - startTime);
    show(v, NUMS, out);
    out << "The Time is : "  << fixed << setprecision(6) << result / CLOCKS_PER_SEC << "s" << endl;
    out.close();
}

void test_selectSort(vector<node> v) {
    ofstream out("selectSort.txt");
    clock_t startTime = clock();

    vector<node> temp(v.size());
    Sorter<node, vector<node>&>::SelectSort(v, 0, v.size() - 1, false);

    clock_t endTime = clock();
    double result = (double)(endTime - startTime);
    show(v, NUMS, out);
    out << "The Time is : "  << fixed << setprecision(6) << result / CLOCKS_PER_SEC << "s" << endl;
    out.close();
}

int main(void) {
    int x;
    vector<node> pass;
    freopen("../password.txt", "r", stdin);
    while (~scanf("%s %d", p, &x)) {
        pass.emplace_back(string(p), x);
    }
    test_Shell(pass);
    test_quickSort(pass);
    test_merageSort(pass);
    test_HeapSort(pass);
    test_RadixSort(pass);
    test_insertSorter(pass);
    test_bullbleSort(pass);
    test_selectSort(pass);

    return 0;
}
