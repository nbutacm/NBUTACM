#include<iostream>
#include<string.h>
using namespace std;
#define ll long long

ll n,m;
ll w[505],p[505];
ll dp[100005];

int main(){
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%lld%lld",&w[i],&p[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=w[i];j<=m;j++){
			dp[j]=max(dp[j],dp[j-w[i]]+p[i]);
		}
	}
	printf("%lld\n",dp[m]);
}
