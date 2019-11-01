#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N=1005;

int n,m;                //n为顶点数、m位边数
int link[N];            //link[y]=x,即y与x匹配
bool vis[N];
vector<int>v[N];
int rec[N][N];

//用dfs寻找增广路
bool can(int u){
    for(int i=0;i<v[u].size();i++){
        int t=v[u][i];
        if(!vis[t]){
            vis[t]=true;
            if(link[t]==-1||can(link[t])){ //如果t尚未被匹配，或者link[t]即x可以找到其他能够替代的点,则把t点让给u匹配
                link[t]=u;
                return true;
            }
        }
    }
    return false;
}
//返回最大匹配数
int max_match(){
    memset(link,-1,sizeof(link));
    int ans=0;
    for(int i=1;i<=n;i++){
        memset(vis,false,sizeof(vis));
        if(can(i))
            ans++;
    }
    return ans;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<=m+n;i++) v[i].clear();
		memset(rec,0,sizeof(rec));
	    int x,a,b;
	    while(~scanf("%d",&x)){
	    	if(x==0)
		    break;
		    scanf("%d%d",&a,&b);
		    if(x==1)
		    //v[a].push_back(b+n);
		    rec[a][b+n]=1;
		    else
		    //v[a+n].push_back(b);
		    rec[a+n][b]=1;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=n+1;j<=n+m;j++){
				if(rec[i][j]&&rec[j][i]){
					ans++;
				}
			}
		}
		printf("%d\n",n+m-ans*2);
	}
}