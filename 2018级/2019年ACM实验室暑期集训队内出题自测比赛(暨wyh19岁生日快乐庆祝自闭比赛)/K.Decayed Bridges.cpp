#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
 
const int maxn = 1e5 + 10;
pair<ll, ll> p[maxn];
ll par[maxn];
ll s[maxn];
ll sum;
ll ans[maxn];
ll find(ll x) { return par[x] == x ? x : par[x] = find(par[x]); }
 
int main() {
    ll n, m;
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        s[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        scanf("%lld%lld", &p[i].first, &p[i].second);
    }
    sum = 1LL * n * (n - 1) / 2;
    for (int i = m - 1; i >= 0; i--) {
        ans[i] = sum;
        int x = find(p[i].first), y = find(p[i].second);
        if (x != y) {
            par[y] = x;
            sum -= s[x] * s[y];
            s[x] += s[y];
        }
    }
    for (int i = 0; i < m; i++) printf("%lld\n", ans[i]); 
    return 0;
}