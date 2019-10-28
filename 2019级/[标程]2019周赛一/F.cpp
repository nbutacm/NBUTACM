#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
int const maxn = 1e5 + 10;
ll a[maxn];
 
int main(void) {
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > x) {
            ans += (a[i] - x);
            a[i] = x;
        }
        if (a[i] + a[i + 1] > x) {
            ans += (a[i] + a[i + 1]) - x;
            a[i + 1] -= (a[i] + a[i + 1]) - x;
        }
    }
    cout << ans << endl;
    return 0;
}
