#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int dp[505][505];
	int n;
	cin>>n;
	for (int i=0;i<=n;i++) dp[i][0]=0;
	for (int j=0;j<=n;j++) dp[0][j]=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			cin>>dp[i][j];
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			dp[i][j]=dp[i][j]+max(dp[i-1][j],dp[i][j-1]);
		}
	}
	cout<<dp[n][n]<<endl;
	return 0;
}
