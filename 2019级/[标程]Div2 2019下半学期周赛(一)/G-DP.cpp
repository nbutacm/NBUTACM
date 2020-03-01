#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int const maxn = 50*10000 + 10;

int dp[maxn], a[maxn];

int main(void) {
    int n, m;
    cin  >> n >> m;
    ll ans = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = sum - m; j >= a[i]; j--) {
            dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
        }
    }
    if (sum < m) {
        cout << -1 << endl;
    } else {
        cout << sum - dp[sum - m] << endl;
    }
    
    return 0;
}
