#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int t,n;
int a[105][105];
int dp[105][105]; 

int dfs(int x,int y){
	if(dp[x][y]!=-1) return dp[x][y];
	if(x==n) return a[x][y];
	return dp[x][y]=a[x][y]+max(dfs(x+1,y),dfs(x+1,y+1));
}

int main(){
	cin>>t;
	while(t--){
		cin>>n;
		memset(a,0,sizeof(a));
		memset(dp,-1,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				cin>>a[i][j];
			}
		}
		int ans=dfs(1,1);
		cout<<ans<<endl;
	}
} 
