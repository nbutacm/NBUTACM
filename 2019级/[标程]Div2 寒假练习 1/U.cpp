#include<iostream>
using namespace std;
int n, m;
long long dp[2005][2005];
#define mod (1000000000 + 7)
int main()
{
	dp[1][1] = 1;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			dp[i][j] = max(dp[i][j], dp[i - 1][j] + dp[i][j - 1]) % mod;
		}
	}
	cout << dp[n][m] % mod << endl;
	return 0;
}
