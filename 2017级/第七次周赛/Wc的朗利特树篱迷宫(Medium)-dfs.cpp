#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int t;
int n,sx,sy;
int ans; 
int vis[105][105];
char pic[105][105];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void dfs(int x,int y,int step){
	if(step>ans) return;   //剪枝（如果step比ans还大的话，没必要再往下搜索下去了） 
	if(pic[x][y]=='E') ans=min(ans,step);
	else{
		vis[x][y]=1;
		for(int i=0;i<4;i++){
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx>=0&&xx<n&&yy>=0&&yy<n&&vis[xx][yy]==0&&pic[xx][yy]!='#'){
				dfs(xx,yy,step+1);
				vis[x][y]=0; 
			}
		}
	}
}



int main(){
	cin>>t;
	while(t--){
		memset(vis,0,sizeof(vis));
		memset(pic,0,sizeof(pic));
		ans=999999999;
		
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>pic[i][j];
				if(pic[i][j]=='S'){
					sx=i;
					sy=j;
				}
			}
		}
		
		dfs(sx,sy,0);
		
		if(ans==999999999) cout<<-1<<endl;
		else cout<<ans<<endl;
	}  
    return 0;
}

