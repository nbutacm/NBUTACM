#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int const maxn = 1e5 + 10;

struct node {
    int x, step;
    node(const int &x = 0, const int &step = 0) : x(x), step(step) { }
};

int prime[maxn];
int v[maxn];

int init() {
    for (int i = 2; i < maxn; i++) {
        if (!prime[i]) {
            for(int j = i * 2; j < maxn; j += i) {
                prime[j] = 1;
            }
        }
    }
}

int bfs(int x, int y) {
    int vis[4];
    queue<node> q;
    q.push(node(x, 0));
    while (!q.empty()) {
        int p = q.front().x;
        v[p] = 1;
        int ans = q.front().step;
        q.pop();
        if (p == y) {
            return ans;
        }
        for (int i = 0; i < 4; i++)  {
            vis[0] = p % 10;
            vis[1] = (p / 10) % 10;
            vis[2] = (p / 100) % 10;
            vis[3] = (p / 1000) % 10;
            int t = vis[i];
            for (int j = (i == 3 ? 1 : 0); j < 10; j++) {
                vis[i] = j;
                int temp = vis[0] + vis[1] * 10 + vis[2] * 100 + vis[3] * 1000;
                if (!v[temp] && !prime[temp] && temp != p) {
                    q.push(node(temp, ans + 1));
                } 
            }
        }
    }
    return -1;
}

int main(void) {

    init();
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        memset(v, 0, sizeof(v));
        int ans = bfs(x, y);
        if (ans != -1) cout << ans << endl;
        else cout << "Impossible" << endl;
    }
    
    return 0;
}
