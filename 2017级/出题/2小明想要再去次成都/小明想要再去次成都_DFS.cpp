#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=105;

int pic[MAXN][MAXN];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

int vis[MAXN][MAXN];
int cnt;
int n,m,t,l;
int step[MAXN][MAXN];

void dfs(int x,int y,int res) {
	for(int i=0;i<4;i++) {
		int xx=dx[i]+x;
		int yy=dy[i]+y;
		
		int ans=abs(pic[xx][yy]-pic[x][y]);
		if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&!vis[xx][yy]&&ans<=l&&step[xx][yy]>step[x][y]+1) {
			step[xx][yy]=step[x][y]+1;
			if(xx==n&&yy==m) return ;
			vis[xx][yy]=1;
			dfs(xx,yy,step[x][y]+1);
			vis[xx][yy]=0;
		}
	}
}

int main() {
	cin>>t;
	while(t--) {
		memset(step,INF,sizeof(step));
		step[1][1]=0;
		memset(vis,0,sizeof(vis));
		cnt=0;
		cin>>n>>m>>l;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				cin>>pic[i][j];
			}
		}
		vis[1][1]=1;
		dfs(1,1,cnt);
		if(n==1&&m==1) cout<<1<<endl;
		else if(step[n][m]==INF) cout<<-1<<endl;
		else cout<<step[n][m]<<endl;
	}
} 
