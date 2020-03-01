#include <bits/stdc++.h>
using namespace std;

char mp[2][15][15];
struct node {
    int x, y, z, t;
    node(const int &x = 0, const int &y = 0, const int &z = 0, const int &t = 0)
        : x(x), y(y), z(z), t(t) {}
};
const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m, T;

int bfs(int x, int y, int z) {
    queue<node> q;
    if (T) q.push(node(x, y, z));
    mp[z][x][y] = '*';
    while (!q.empty()) {
        node p = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            node tp = p;
            tp.x += dir[i][0];
            tp.y += dir[i][1];
            tp.t++;
            if (tp.x < 0 || tp.x >= n || tp.y < 0 || tp.y >= m) continue;
            if (mp[tp.z][tp.x][tp.y] == '*') continue;
            if (mp[tp.z][tp.x][tp.y] == '#') {
                mp[tp.z][tp.x][tp.y] = '*';
                tp.z ^= 1;
                if (mp[tp.z][tp.x][tp.y] == '#') mp[tp.z][tp.x][tp.y] = '*';
                if (mp[tp.z][tp.x][tp.y] == '*') continue;
            }
            if (mp[tp.z][tp.x][tp.y] == 'P') return tp.t;
            mp[tp.z][tp.x][tp.y] = '*';
            if (tp.t < T) {
                q.push(tp);
            }
        }
    }

    return -1;
}

int main(void) {
    int q;
    scanf("%d", &q);
    while (q--) {
        int x, y, z;
        scanf("%d%d%d", &n, &m, &T);
        for (int i = 0; i < n; i++) {
            scanf("%s", mp[0][i]);
            for (int j = 0; j < m; j++) {
                if (mp[0][i][j] == 'S') {
                    x = i, y = j, z = 0;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            scanf("%s", mp[1][i]);
            for (int j = 0; j < m; j++) {
                if (mp[1][i][j] == 'S') {
                    x = i, y = j, z = 1;
                }
            }
        }
        if (-1 == bfs(x, y, z)) {
            puts("NO");
        } else {
            puts("YES");
        }
    }

    return 0;
}
