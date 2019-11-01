#include<iostream>
using namespace std;
typedef long long ll;
const ll MOD=1000000007;


int n;

ll powermod(ll a,ll b,ll c){
	ll ans=1;
	a%=c;
	while(b){
		if(b%2==1) ans=ans*a%c;
		a=a*a%c;
		b=b/2;
	}
	return ans;
}

int main(){
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	while(cin>>n){
		cout<<powermod(2,n*n-1,MOD)<<endl;
	}
}
