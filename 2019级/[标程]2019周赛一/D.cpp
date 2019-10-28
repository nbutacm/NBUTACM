#include <bits/stdc++.h>

using namespace std;
int const maxn = 1e5 + 10;
typedef long long ll;
ll a[maxn], b[maxn];

int main(void) {
    int n;
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            b[i] = b[i - 1] + a[i];
        }
        ll sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += 1LL * a[i] * (b[n] - b[i]);
        }
        cout << sum << endl;
    }
    return 0;
}
