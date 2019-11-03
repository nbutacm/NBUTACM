#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1e5+20;

int n,u,v;
vector<int>g[N];
int dis[N],f[N],tag[N];

void dfs(int u,int fa){
	f[u] = fa;
	for(int i=0;i<(int)g[u].size();i++){
		int v = g[u][i];
		if(fa==v) continue;
		if(tag[v]) continue;
		dis[v] = dis[u] + 1;
		dfs(v,u);
	}
}

void init(){
	for(int i=1;i<N;i++) g[i].clear();
	memset(dis,0,sizeof(dis));
	memset(f,0,sizeof(f));
	memset(tag,0,sizeof(tag));
}

int main(){
	//ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int T;
	cin >> T;
	while(T--){
		init();
		cin >> n;
		for(int i=1;i<n;i++){
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
		dfs(1,-1);
		int st = max_element(dis+1,dis+n+1) - dis;
		memset(dis,0,sizeof(dis));
		dfs(st,-1);
		int ed = max_element(dis+1,dis+n+1) - dis;
		
		int len = dis[ed], pos = ed;
		while(pos!=-1){
			dis[pos] = max(dis[pos], len-dis[pos]);
			tag[pos] = 1;
			pos = f[pos];
		}
		for(int i=1;i<=n;i++){
			if(tag[i]){
				dfs(i,-1);
			}
		}
		for(int i=1;i<=n;i++){
			if(i!=1) cout << ' ';
			cout << dis[i];
		}
		cout << endl;
	}
	return 0;
}
