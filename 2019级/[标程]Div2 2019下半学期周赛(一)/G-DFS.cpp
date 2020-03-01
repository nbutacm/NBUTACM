#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int const maxn = 50 + 10;
int const INF = 0x3f3f3f3f;
int ans(INF);
int vis[maxn], a[maxn];
int n, m;

void dfs(int id, int sum) {
	if (sum > ans){
		return;
	}
    if (sum >= m) {
        ans = sum;
        return;
    }
    for (int i = id; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            dfs(id + 1, sum + a[i]);
            vis[i] = 0;
        }
    }
}

int main(void) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(1,0);
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}
