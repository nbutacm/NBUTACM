#include <iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
#define ll long long

ll dp[50005];
ll n,v;

// 背包模板 

void ZeroOnePack(ll cost,ll value){//01
	for(ll j=v;j>=cost;j--){
		dp[j]=max(dp[j],dp[j-cost]+value);
	}
}

void CompletePack(ll cost,ll value){//完全
	for(ll j=cost;j<=v;j++){
		dp[j]=max(dp[j],dp[j-cost]+value);
	}
}

void MultiplePack(ll cost,ll value,ll cnt){//多重
	if(v<=cnt*cost){//如果总容量比这个物品的容量要小,那么这个物品可以直到取完,相当于完全背包.
		CompletePack(cost,value);
		return ;
	}
	else{//否则就将多重背包转化为01背包
		/********二进制优化**********/
		ll k=1;
		while(k<=cnt){
			ZeroOnePack(k*cost,k*value);
			cnt=cnt-k;
			k=2*k;
		}
		ZeroOnePack(cnt*cost,cnt*value);
		/********暴力超时*************/
		/*for(ll i=1;i<=cnt;i++){
            ZeroOnePack(i*cost,i*value);
		}*/
	}
}

int main ()
{
    cin>>n>>v;
    ll w,p,c;
    while(n--){
        cin>>w>>p>>c;
        MultiplePack(w,p,c);
    }
    cout<<dp[v]<<endl;

  return 0;
}
