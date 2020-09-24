#include <bits/stdc++.h>
#include "LinkedList.h"

#define FAST_IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)

using namespace std;

int main(void) {
    FAST_IO;

    freopen("../user.txt", "r", stdin);
    List<int> userList;
    string name;
	int id;
    while (cin >> id >> name) {
        userList.push(id);
    }
    cout << "读入成功 链表创建成功...." << endl;
    ifstream fin("../random_id.txt", ios::in);
    clock_t startTime = clock();
    int cnt = 0;
    while (fin >> id) {
        if (userList.find(id)) {
            cnt++;
        }
    }
    clock_t endTime = clock();
    fin.close();
	ofstream fout("list_find.txt", ios::out);
    cout << "The total of find for LinkList: " << cnt << " users" << endl;
    fout << "The run time for LinkList is: " << fixed << setprecision(3) << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;


    return 0;
}
