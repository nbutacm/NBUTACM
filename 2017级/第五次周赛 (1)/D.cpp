#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

#define ll long long
const ll MAXN=1e6+5;

ll n;
ll a[MAXN];

int main(){
	scanf("%lld",&n);
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	
	ll flag=n;       //flag 表示 位置在flag后面的人都死了 
	ll ans=0;        //表示存活的人数 
	
	for(int i=n-1;i>=0;i--){      //倒着往前推 
		if(i<flag){               //如果第i个人在flag前面，说明他没有被后面的人杀死，还活着 
			ans++;
		}
		ll temp=i-a[i];           //判断第i个人可以往前杀到第几个人 
		flag=min(flag,temp);      //如果第i个人可以杀得比flag还前面，就让flag=temp； 
	}
	printf("%lld",ans);
}

