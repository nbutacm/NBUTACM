#include <bits/stdc++.h>
using namespace std; 

int main(void) {
 
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto &x : v) {
        cin >> x;
    }
    sort(v.begin(), v.end());
    int l = 0, r = n - 1;
    int ans = 0;
    while (l < r) {
        if (v[l] + v[r] <= m) {
            l++, r--;
            ans++;
        } else {
            ans++;
            r--;
        }
    }
    if (l == r) ans++;
    cout << ans << endl;
    
    return 0;
}
