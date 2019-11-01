// F - Wc�������������Թ�(��) NBUT - 1721


#include<iostream>
#include<cstring>
using namespace std;

int t;
int n,k;
char pic[105][105];
int vis[105][105];
int sx,sy,ex,ey,mx,my,_k;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void dfs(int x,int y){
	vis[x][y]=1;
	if(pic[x][y]=='K') _k++;          //����ҵ�Կ�ף�Կ������+1 
	for(int i=0;i<4;i++){
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(xx>=0&&xx<n&&yy>=0&&yy<n&&vis[xx][yy]==0&&pic[xx][yy]!='#'){
			if(pic[xx][yy]=='M') vis[xx][yy]=1;        //����ҵ��ţ�����ű��ҵ��������ǻ������ܽ���    
			else{
				dfs(xx,yy);
			}
		}
	}
}

int main(){
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	cin>>t;
	while(t--){
		memset(pic,0,sizeof(pic));
		memset(vis,0,sizeof(vis));
		cin>>n>>k;
		_k=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>pic[i][j];
				if(pic[i][j]=='S'){
					sx=i;sy=j;
				}
				if(pic[i][j]=='E'){
					ex=i;ey=j;
				}
				if(pic[i][j]=='M'){
					mx=i;my=j;
				}
			}
		}
		bool flag=false;
		dfs(sx,sy);
		if(vis[ex][ey]==1){            //�����ֱ���ߵ��յ� 
			flag=true;
		}
		else{                         //���� 
			if(_k>=k&&vis[mx][my]==1){       //���Կ������������ſ��Ա��ߵ�  
				dfs(mx,my);                 //��dfsһ�� 
				if(vis[ex][ey]==1){         //������ߵ��յ� 
					flag=true;
				}
			}
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
