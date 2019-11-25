#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<string, int> mp;

int main(void) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        sort(s.begin(),s.end());
        mp[s]++;
    }
    
    ll ans = 0;
    for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        ll m = it->second;
        if (m < 2) continue;
        ans += m * (m - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}

