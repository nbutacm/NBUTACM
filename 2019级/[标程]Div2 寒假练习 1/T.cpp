#include <bits/stdc++.h>
using namespace std;

int const maxn = 200 + 10;
const int INF = 0x3f3f3f3f;

int n, m;
int vis1[maxn][maxn];
int vis2[maxn][maxn];
int mp2[maxn][maxn];
char mp[maxn][maxn];
int dis1[maxn][maxn], dis2[maxn][maxn];

struct node {
    int x, y, step, v;
    node(int x = 0, int y = 0, int step = 0, int v = 0)
        : x(x), y(y), step(step), v(v) {}
};

int const dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};

int x1, x2, y1, y2;
void bfs() {
    queue<node> q;
    q.push(node(x1, y1, 0, 1));
    q.push(node(x2, y2, 0, 2));
    while (!q.empty()) {
        node tq = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int tx = tq.x + dir[i][0];
            int ty = tq.y + dir[i][1];
            if (tx >= 0 && tx < n && ty >= 0 && ty < m && mp[tx][ty] != '#') {
                if (tq.v == 1) {
                    if (vis1[tx][ty]) continue;
                    q.push(node(tx, ty, tq.step + 1, 1));
                    vis1[tx][ty] = 1;
                    dis1[tx][ty] = tq.step + 1;
                } else {
                    if (vis2[tx][ty]) continue;
                    q.push(node(tx, ty, tq.step + 1, 2));
                    vis2[tx][ty] = 1;
                    dis2[tx][ty] = tq.step + 1;
                }
            }
        }
    }
}

int main(void) {
    while (cin >> n >> m) {
        memset(dis1, 0x3f, sizeof(dis1));
        memset(dis2, 0x3f, sizeof(dis2));
        memset(vis1, 0, sizeof(vis1));
        memset(vis2, 0, sizeof(vis2));
        for (int i = 0; i < n; i++) {
            cin >> mp[i];
            for (int j = 0; j < m; j++) {
                if (mp[i][j] == 'Y') {
                    x1 = i, y1 = j;
                }
                if (mp[i][j] == 'M') {
                    x2 = i, y2 = j;
                }
            }
        }
        vis1[x1][y1] = vis1[x2][y2] = 1;
        vis2[x1][y1] = vis2[x2][y2] = 1;
        dis1[x1][y1] = 0;
        dis2[x2][y2] = 0;
        bfs();
        int ans = INF;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mp[i][j] == '@' && dis1[i][j] != INF && dis2[i][j] != INF &&
                    dis1[i][j] + dis2[i][j] <= ans) {
                    ans = dis1[i][j] + dis2[i][j];
                }
            }
        }
        cout << ans * 11 << endl;
    }

    return 0;
}
