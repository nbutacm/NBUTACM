// 完全背包

#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int dp[10005];
	int t,n,i,j;
	int w[3]={150,200,350};
	cin >> t;
	while(t--){
		memset(dp,0,sizeof(dp));
		cin >> n;
		for(i=0;i<3;i++){
			for(j=w[i];j<=n;j++){
				dp[j] = max(dp[j],dp[j-w[i]]+w[i]);
			}
		}
		cout << n-dp[n] << endl;
	}
	return 0;
}


// 直接判断

#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		if(n<150){
			cout << n << endl;
			continue;
		}
		if(n>=250&&n<300){
			cout << n-200 << endl;
		}
		else{
			cout << n%50 << endl;
		}
	}
	return 0;
}
