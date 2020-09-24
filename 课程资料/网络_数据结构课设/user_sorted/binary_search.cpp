#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>

using namespace std;
int const maxn = 1230000 + 10;
int userid[maxn];
char p[50];
int cnt = 0;

int binary_search(int a[], int l, int r, int key) {
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (a[mid] > key) {
            r = mid - 1;
        } else if (a[mid] < key) {
            l = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int main(void) {
    ifstream userin("user_sort.txt");
    ifstream test("../random_id.txt");
    int t = 0;
    int x;
    
    while (userin >> x >> p) {
        userid[t++] = x;
    }
    double tot = 0;
    cout << t << endl;
	cout << "读入数据完成" << endl; 
	
    while (test >> x) {
        clock_t startTime = clock();
        if (binary_search(userid, 0, t - 1, x) != -1) {
            cnt++;
        }
        clock_t endTime = clock();
        tot += endTime - startTime;
    }
    
    ofstream out("binary_search.txt");
    out << "success of " << cnt << endl;
    out << "The run time is " << fixed << setprecision(3) << tot / CLOCKS_PER_SEC << "s" << endl;

    return 0;
}
