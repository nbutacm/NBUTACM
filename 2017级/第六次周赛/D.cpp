#include <map>
#include <iostream>
#include<string.h>
using namespace std;

int t;
int n,sx,sy,ex,ey,num_end;
bool flag;
int vis[105][105];
char pic[105][105];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};


struct node{
	int x,y;
}start,end[10005]; 

void dfs(int x,int y){
	vis[x][y]=1;
	for(int i=0;i<4;i++){
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(xx>=0&&xx<n&&yy>=0&&yy<n&&vis[xx][yy]==0&&pic[xx][yy]!='#'){
			dfs(xx,yy);
		}
	}
}

int main(){
	//freopen("data.in","r",stdin);
	cin>>t;
	while(t--){
		memset(vis,0,sizeof(vis));
		memset(pic,0,sizeof(pic));
		memset(end,0,sizeof(end));
		num_end=0;
		flag=false;
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>pic[i][j];
				if(pic[i][j]=='S'){
					start.x=i;
					start.y=j;
				}
				if(pic[i][j]=='E'){
					end[num_end].x=i;
					end[num_end].y=j;
					num_end++;
				}
			}
		}
		
		dfs(start.x,start.y);
		for(int i=0;i<num_end;i++){
			int x=end[i].x;
			int y=end[i].y;
			if(vis[x][y]==1){
				flag=true;
				break;
			}
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}  
    return 0;
}
