#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <iomanip> 
#include <stack>
#include <stdlib.h>	
#include <stdio.h>
#define INF 0x3f3f3f3f
#include <set> 
#include <map>  
#include <queue>
#define LC(a) (a<<1)
#define RC(a) (a<<1|1)//乘以二 
#define MID(a,b) ((a+b)>>1)//除以二 
using namespace std;
typedef long long ll;
int a[10005],dp[10005][2];
int main(){
	int n;
	while(~scanf("%d",&n)){
		int ans=0;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		memset(dp,0,sizeof(dp));
		dp[1][0]=a[1],dp[2][0]=a[2];
		dp[1][1]=0,dp[2][1]=0;
		for(int i=3;i<=n;i++){
			dp[i][0]=min(dp[i-1][1],dp[i-1][0])+a[i];
			dp[i][1]=min(dp[i-1][0],dp[i-2][0]);
		}
		printf("%d\n",min(dp[n][0],dp[n][1]));
	} 
	return 0; 
}