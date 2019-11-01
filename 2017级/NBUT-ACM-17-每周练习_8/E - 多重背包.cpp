#include <iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
#define ll long long

ll dp[50005];
ll n,v;

// ����ģ�� 

void ZeroOnePack(ll cost,ll value){//01
	for(ll j=v;j>=cost;j--){
		dp[j]=max(dp[j],dp[j-cost]+value);
	}
}

void CompletePack(ll cost,ll value){//��ȫ
	for(ll j=cost;j<=v;j++){
		dp[j]=max(dp[j],dp[j-cost]+value);
	}
}

void MultiplePack(ll cost,ll value,ll cnt){//����
	if(v<=cnt*cost){//����������������Ʒ������ҪС,��ô�����Ʒ����ֱ��ȡ��,�൱����ȫ����.
		CompletePack(cost,value);
		return ;
	}
	else{//����ͽ����ر���ת��Ϊ01����
		/********�������Ż�**********/
		ll k=1;
		while(k<=cnt){
			ZeroOnePack(k*cost,k*value);
			cnt=cnt-k;
			k=2*k;
		}
		ZeroOnePack(cnt*cost,cnt*value);
		/********������ʱ*************/
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
