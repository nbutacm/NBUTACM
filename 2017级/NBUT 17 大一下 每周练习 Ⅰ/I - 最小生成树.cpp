#include <iostream>
#include <cmath>
#include <cstring> 
#include <queue>
#include <algorithm>
#define FAST_IO ios::sync_with_stdio(false)
#define mem(a) memset(a,0,sizeof(a))
using namespace std;
typedef long long ll;
const double pi = acos(-1.0);
const int INF=0x3f3f3f3f;
const int maxn=30;


/*
用结构体存图的边
然后使用Kruskal算法求最小生成树

*/

int n,cnt;
struct edge{
	int from,to;
	int cost;
}g[maxn*maxn];
int fa[maxn];

void init()
	cnt = 0;
	for(int i=1;i<=n;i++) fa[i] = i;
}

int fd(int x){
	return x == fa[x] ? x : fa[x] = fd(fa[x]);
}

bool join(int x,int y){
	int u = fd(x),v = fd(y);
	if(u==v) return 1;
	fa[u] = v;
	return 0;
}

bool cmp(edge a,edge b){
	return a.cost < b.cost;
}

int Kruskal(){
	int ans = 0;
	sort(g+1,g+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		if(!join(g[i].from,g[i].to)){
			ans += g[i].cost;
		}
	}
	return ans;
}


int main(){
	while(cin >> n&&n){
		init();
		char c1,c2;
		int num,cost;
		for(int i=1;i<n;i++){
			cin >> c1;
			cin >> num;
			for(int j=1;j<=num;j++){
				cin >> c2 >> cost;
				cnt++;
				g[cnt].cost = cost;
				g[cnt].from = (int)(c1-'A'+1);
				g[cnt].to   = (int)(c2-'A'+1);
			}
		}
		int ans = Kruskal();
		cout << ans << endl;
	}
	return 0;
}