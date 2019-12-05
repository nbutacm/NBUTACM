#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
const int MOD=1e9+7;

int n,m;
int dp[1005][1005];

int main(){
	cin>>n>>m;
	for(int i=0;i<=n;i++) dp[i][0]=0;
	for(int i=0;i<=m;i++) dp[0][i]=0;
	dp[0][1]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
		}
	}
	cout<<dp[n][m]<<endl;
}

//    如果要去 (i,j) 点 那么只能从 (i-1,j)或(i,j-1)这两点出发  
//    所以到达(i,j)点的走法为到(i-1,j)点和到(i,j-1)点这两点的走法之和   
