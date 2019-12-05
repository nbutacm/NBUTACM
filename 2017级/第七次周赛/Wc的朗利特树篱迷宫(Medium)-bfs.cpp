#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;

int t;
int n,sx,sy;
int ans; 
int vis[105][105];
char pic[105][105];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

struct node{
	int x,y,step;
};

int bfs(int x,int y){
	node u;
	u.x=x;
	u.y=y;
	u.step=0;
	vis[x][y]=1;
	queue<node>q;
	q.push(u);
	while(!q.empty()){
		node v=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int xx=v.x+dx[i];
			int yy=v.y+dy[i];
			if(xx>=0&&xx<n&&yy>=0&&yy<n&&vis[xx][yy]==0&&pic[xx][yy]!='#'){
				if(pic[xx][yy]=='E'){
					return v.step+1;          //根据bfs的特点，第一个找到的一定是路程最短的 
				}
				else{
					vis[xx][yy]=1;
					node w;
					w.x=xx;
					w.y=yy;
					w.step=v.step+1;
					q.push(w);
				}
			}
		}
	}
	return -1;
}

int main(){
	cin>>t;
	while(t--){
		memset(vis,0,sizeof(vis));
		memset(pic,0,sizeof(pic));
		
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
		
		ans=bfs(sx,sy);
		cout<<ans<<endl;
	}  
    return 0;
}

