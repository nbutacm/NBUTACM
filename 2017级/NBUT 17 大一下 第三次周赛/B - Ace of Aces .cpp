#include<iostream>
#include<bits/stdc++.h>
#include<map>
using namespace std;
const int maxn= 1e6+7;
typedef long long ll;
int T,n,x,ans,a[maxn],j,flag;
int main(){
 	scanf("%d",&T);
 	while(T--){
 		ans=0,flag=0,j=0;
 		map<int,int>tem;
 		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			tem[x]++;
			if(tem[x]>ans){
				ans=tem[x];
				j=x;
			}
		}
		map<int,int>::iterator it=tem.begin();
		for(it;it!=tem.end();it++){
			if((*it).second==ans&&(*it).first!=j){
				printf("Nobody\n");
				flag=1;
				break;
			}
		}
		if(flag==0) printf("%d\n",j);
	}
}