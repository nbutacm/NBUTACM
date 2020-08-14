#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <map>
#define pi acos(-1.0)
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fLL
#define ms(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
vector<int> maze1[1100];
vector<int> maze2[1100];
int vis[1100];
int vist[1100];
int ans[1100];
int bck[1100];
int cnt = 0;
int res = 0;
void bfs()
{
    queue<int>q;
    vis[1] = 1;
    bck[cnt++] = 1;
    q.push(1);
    while (q.size()) {
        int x = q.front(); q.pop();
        if (!maze1[x].size()) {
            ans[x] = 1;
        }
        else {
            for (int i = 0; i < maze1[x].size(); i++) {
                int y = maze1[x][i];
                if (vis[y])continue;
                vis[y] = 1;
                q.push(y);
                bck[cnt++] = y;
            }
        }
    }
}
void dfs(int x)
{
    if (vist[x] || vis[x])
        return;
    if (maze1[x].size() == 0) {
        ans[x] = 1;
        return;
    }
    vist[x] = 1;
    for (int i = 0; i < maze1[x].size(); i++) {
        int y = maze1[x][i];
        dfs(y);
        
    }
}
int main()
{
    int x, y;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        if (x < 0)
            maze1[-x].push_back(y);
        else
            maze2[x].push_back(y);
    }
    bfs();
    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < maze2[bck[i]].size(); j++) {
            dfs(maze2[bck[i]][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (ans[i])res++;
    }
    cout << res;
}