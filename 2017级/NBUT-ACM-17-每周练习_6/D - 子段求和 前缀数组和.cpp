#include<iostream>
#include<stdio.h>
#define ll long long
using namespace std;

ll n,q;
ll a[50005];
ll dp[50005];

int main(){
	scanf("%lld",&n);
	dp[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		dp[i]=dp[i-1]+a[i];
	}
	
	scanf("%lld",&q);
	ll pos,len;
	while(q--){
		scanf("%lld%lld",&pos,&len);
		printf("%lld\n",dp[pos+len-1]-dp[pos-1]);
	}
	
	return 0; 
} 




// ���⻹������ ����״���飡  ��  ���߶�����  д�������ȿ������Ժ���������Ҫ��һ�� 
