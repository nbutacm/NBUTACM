#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#define ll long long
using namespace std;
const ll N=1e17;
int main(){
    ll ans=N;
    ll n,p,q;
    scanf("%lld%lld%lld",&n,&p,&q);
    for(ll i=0;i<=n;i++){
        ll jour=n-i,num=i+1;
        ans=min(ans,i*q+p*(num-jour%num)*(jour/num)*(jour/num)+p*(jour%num)*(jour/num+1)*(jour/num+1));
    }
    printf("%lld",ans);
    return 0;
} 
