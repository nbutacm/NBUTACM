#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAX = 1e2 + 10;
typedef long long LL;

char s[MAX][MAX];
int n,m,vis[MAX][MAX];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void dfs(int x,int y,char c){
    vis[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int xx = x + dx[i],yy = y + dy[i];
        if(xx >= 0 && yy >= 0 && xx <= n+1 && yy <= m+1 && vis[xx][yy]==0 && s[xx][yy] == c){
            dfs(xx,yy,c);
        }
    }
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
	    for(int i = 1; i <= n; i++){
	    	for(int j=1;j<=m;j++){
	    		cin>>s[i][j];
			}
		}
		
	    for(int i = 0; i <= n+1; i++) s[i][0] = s[i][m+1] = '0';
	    for(int i = 0; i <= m+1; i++) s[0][i] = s[n+1][i] = '0';
	    memset(vis,0,sizeof(vis));
	    int x1 = 0,x0 = 0;
	    
	    for(int i = 0; i <= n+1; i++){
	    	for(int j = 0; j <= m+1; j++){
	            if(vis[i][j]==0){
	                if(s[i][j] == '1') x1++;
	                else x0++;
	                dfs(i,j,s[i][j]);
	            }
	        }
		}
		
	    if(x1 == 1 && x0 == 1) cout<<1<<endl;
	    else if(x1 == 1 && x0 == 2)	cout<<0<<endl;
	    else cout<<-1<<endl;
	}
}
