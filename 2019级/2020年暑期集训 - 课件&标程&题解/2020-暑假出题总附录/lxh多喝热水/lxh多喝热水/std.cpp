#include<cstdio>
#include<queue>
#include<fstream>
using namespace std;
const int MAXN = 1e5+5;
const int MAXM = 2e5+5;

inline int read() {
    int x = 0;
    char c = getchar();
    while(c < '0' || c > '9')
        c = getchar();
    while(c >= '0' && c <= '9') {
        x = x*10 + c-'0';
        c = getchar();
    }

    return x;
}

int tot;
int n, m;
int in[MAXN];
int dp[MAXN];
int head[MAXN];
int to[MAXM<<1];
int nxt[MAXM<<1];

void add(int x,int y) {
    nxt[++tot] = head[x];
    head[x] = tot;
    to[tot] = y;
}

void inp() {

    n = read();
    m = read();

    for(int i = 1; i <= m; i++) {
        int x, y;
        x = read();
        y = read();
        add(x,y);
        in[y]++;
    }
}

void topo() {
    queue<int>q;
    for(int i = 1; i <= n; i++)
        if(!in[i]) {
            q.push(i);
            dp[i] = 1;
        }
    
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int i = head[x]; i ; i = nxt[i]) {
            in[to[i]]--;
            dp[to[i]] = max(dp[x]+1,dp[to[i]]);
            if(!in[to[i]])
                q.push(to[i]);
        }
    }
}

int main() {

    inp();

    topo();

    for(int i = 1; i <= n; i++)
        printf("%d\n",dp[i]);

    return 0;
}