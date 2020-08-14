#include<bits/stdc++.h>
#define enter puts("") 
using namespace std;
  
char mp[15][15];
int to[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
int n, m;
struct node {
    int x, y;
} head, app;
  
struct node2 {
    int x, y;
    unsigned bits;
    int step;
} now, nex;
  
void BinaryRecursion(int n) {// 递归输出二进制
    int a;
    a = n % 2;
    n = n >> 1;
    if (n == 0);
    else
        BinaryRecursion(n);
    cout << a;
}
  
int len;
  
void getS(int nowX, int nowY, int nxt, unsigned nowBits) {
    if (nowX != 0 && mp[nowX - 1][nowY] == '0' + nxt)
        getS(nowX - 1, nowY, nxt + 1, (nowBits << 1u) << 1u);//00
    else if (nowY != 0 && mp[nowX][nowY - 1] == '0' + nxt)
        getS(nowX, nowY - 1, nxt + 1, ((nowBits << 1u) << 1u) + 1u);//01
    else if (nowX < n && mp[nowX + 1][nowY] == '0' + nxt)
        getS(nowX + 1, nowY, nxt + 1, ((nowBits << 1u) + 1u) << 1u);//10
    else if (nowY < m && mp[nowX][nowY + 1] == '0' + nxt)
        getS(nowX, nowY + 1, nxt + 1, (((nowBits << 1u) + 1u) << 1u) + 1u);//11
    else {
//        BinaryRecursion(nowBits);
        len = nxt - 1;
        now.x = head.x, now.y = head.y, now.bits = nowBits;
        return;
    }
}
  
int vis[15][15];
  
bool hit(int x, int y, int bfx, int bfy, unsigned bits) {
    if (x < 0 || y < 0 || x >= n || y >= m)return true;
    if (mp[x][y] == '#')return true;
    set<pair<int,int>> ocu;
    int nowX = bfx, nowY = bfy;
    stack<pair<int,int>> s;
    int cnt = 0;
    while (cnt < len - 1) {//去掉头长
        unsigned t2 = bits & 1u;//y
        bits >>= 1u;
        unsigned t1 = bits & 1u;//x
        bits >>= 1u;
        s.push({t1, t2});
        cnt++;
    }
    if (s.empty())return false;//没有尾巴撞个吉尔
    unsigned tot;
    (s.size() == 1) ? (tot = s.size()) : (tot = s.size() - 1);
    while (tot) {//撞尾巴不算撞   但是如果只有两节还是要撞啊
        tot--;
        pair<int,int> tmp = s.top();
        if (tmp.first == 1 && tmp.second == 1)nowY++;
        else if (tmp.first == 1 && tmp.second == 0)nowX++;
        else if (tmp.first == 0 && tmp.second == 1)nowY--;
        else if (tmp.first == 0 && tmp.second == 0)nowX--;
  
        ocu.insert({nowX, nowY});
        s.pop();
    }
    if (ocu.count({x, y}))return true;
    return false;//没撞
}
  
  
int bfs() {
    queue<node2> q;
    q.push(now);
    vis[now.x][now.y] = 1;
    while (!q.empty()) {
        if (now.step > 2000) {
            return -1;
        }
        now = q.front();
        q.pop();
        vis[now.x][now.y] = 0;
        if (mp[now.x][now.y] == '@') {
            return now.step;
        }
        for (int i = 0; i < 4; i++) {
            nex.x = now.x + to[i][0], nex.y = now.y + to[i][1], nex.step = now.step + 1,
            nex.bits = now.bits >> 2u;
            if (len != 1)nex.bits += (((i == 1 || i == 3) ? 1u : 0u)) << ((unsigned) (len - 1) * 2u - 1u);
            if (len != 1)nex.bits += (((i == 0 || i == 1) ? 1u : 0u)) << ((unsigned) (len - 1) * 2u - 2u);
            if (hit(nex.x, nex.y, now.x, now.y, now.bits))continue;
            if (vis[nex.x][nex.y])continue;
            q.push(nex);
            vis[nex.x][nex.y] = 1;
        }
    }
    return -1;
}
  
void init() {
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", mp[i]);
        for (int j = 0; j < m; ++j) {
            if (mp[i][j] == '1') {
                head.x = i, head.y = j;
            } else if (mp[i][j] == '@') {
                app.x = i, app.y = j;
            }
        }
    }
    getS(head.x, head.y, 2, 0u);
    printf("%d",bfs());
    enter;
}
  
int main() {
    init();
    return 0;
}
 
