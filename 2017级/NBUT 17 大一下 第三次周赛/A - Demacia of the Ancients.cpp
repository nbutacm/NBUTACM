#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int maxn= 1e6+7;
typedef long long ll;
int T,n,x,ans;
int main(){
	scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			if(x>6000) ans+=1;
		}
		cout<<ans<<endl;
	}
}