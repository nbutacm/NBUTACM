#include <iostream>
#include <iomanip>
#include <bitset>
#include <string>
#include <set>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <memory>
#include <climits>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

void solve() {
    int n;
    cin >> n;
    priority_queue<double, vector<double>, greater<double> > q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }
    for (int i = 0; i < n - 1; i++) {
        double x = q.top();
        q.pop();
        double y = q.top();
        q.pop();
        q.push((x + y) / 2);
    }
    cout << q.top() << endl;
}

int main(void) {
	
    solve();
    
    return 0;
}

