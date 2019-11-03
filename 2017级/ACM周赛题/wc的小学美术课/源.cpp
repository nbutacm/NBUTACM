#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX = 1e2 + 10;
typedef long long LL;
char s[MAX][MAX];
int n,m,vis[MAX][MAX];
int fx[4] = {0,0,-1,1},fy[4] = {-1,1,0,0};
void dfs(int x,int y,char c){
    vis[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int xx = x + fx[i],yy = y + fy[i];
        if(xx >= 0 && yy >= 0 && xx <= n && yy <= m && !vis[xx][yy] && s[xx][yy] == c){
            dfs(xx,yy,c);
        }
    }
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		while(~scanf("%d %d",&n,&m)){
	        for(int i = 1; i <= n; i++)
	            scanf("%s",s[i] + 1);
	        n++,m++;
	        for(int i = 0; i <= n; i++) s[i][0] = s[i][m] = '0';
	        for(int i = 0; i <= m; i++) s[0][i] = s[n][i] = '0';
	        memset(vis,0,sizeof(vis));
	        int x1 = 0,x0 = 0;
	        for(int i = 0; i <= n; i++)
	            for(int j = 0; j <= m; j++){
	                if(!vis[i][j]){
	                    if(s[i][j] == '1') x1++;
	                    else x0++;
	                    dfs(i,j,s[i][j]);
	                }
	            }
	        if(x1 == 1 && x0 == 1) puts("1");
	        else if(x1 == 1 && x0 == 2) puts("0");
	        else puts("-1");
	    }
	}
    return 0;
}
