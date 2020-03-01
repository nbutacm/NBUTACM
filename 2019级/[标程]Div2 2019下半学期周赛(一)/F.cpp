#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
int main(void) {
    int n;
    ll ans = 0, x;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        ans += (x - 1) * (i - 1) + x;
    }
    cout << ans << endl;
    
    return 0;
}
