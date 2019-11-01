#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int t;
int n,v;
int w[1005],p[1005];
int dp[1005];

int main(){
	cin>>t;
	while(t--){
		cin>>n>>v;
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++) cin>>p[i];
		for(int i=0;i<n;i++) cin>>w[i];
		for(int i=0;i<n;i++){
			for(int j=v;j>=w[i];j--){
				dp[j]=max(dp[j],dp[j-w[i]]+p[i]);
			}
		}
		cout<<dp[v]<<endl;
	}
}
