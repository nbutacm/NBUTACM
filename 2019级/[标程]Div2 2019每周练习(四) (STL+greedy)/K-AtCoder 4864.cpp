#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {

    int n, m;
    cin >> n >> m;
    priority_queue<int> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }
    for (int i = 0; i < m; i++) {
        int t = q.top();
        q.pop();
        t /= 2;
        q.push(t);
    }
    ll ans = 0;
    while (!q.empty()) {
        ans += q.top();
        q.pop();
    }
    cout << ans << endl;
    
    return 0;
}

