#include<iostream>
#define ll long long
using namespace std;

ll n,k;
ll a[10005];
ll dp[10005];

int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=dp[i-1]+a[i];
	}
	bool flag=true;
	for(int i=0;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ll temp=dp[j]-dp[i];
			if(temp==k){
				flag=false;
				cout<<i+1<<" "<<j<<endl;
				break;
			}
		}
		if(flag==false) break;
	}
	if(flag==true) cout<<"No Solution"<<endl;
	
	return 0;
}
