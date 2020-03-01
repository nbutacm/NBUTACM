#include <bits/stdc++.h>

using namespace std;
int const maxn = 2e5 + 10;
const int INF = 0x3f3f3f3f;

char s[maxn];
int main(void) {
    int t, n;
    
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s;
        int l = -1, r = -1, x = 0, y = 0;
        map<pair<int, int>, int> mp;
        mp[{0, 0}] = -1;
        int len = INF;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') x += 1;
            if (s[i] == 'R') x -= 1;
            if (s[i] == 'U') y += 1;
            if (s[i] == 'D') y -= 1;
            if (mp.count({x, y})) {
                if (len > i - mp[{x, y}]) {
                    l = mp[{x, y}] + 1;
                    r = i;
                    len = r - l + 1;
                }
            }
            mp[{x, y}] = i;
        }
        if (l != -1) {
            cout << ++l << " " << ++r << endl;
        } else {
            cout << -1 << endl;
        }
    }
    
    return 0;
}