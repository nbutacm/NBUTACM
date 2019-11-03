#include<iostream>
using namespace std;
typedef long long ll;

ll powermod(ll a,ll b,ll c){
	ll ans=1;
	a%=c;
	cout<<a<<" "<<b<<" "<<ans<<endl;
	while(b){
		if(b%2==1) ans=ans*a%c;
		a=a*a%c;
		b=b/2;
		cout<<a<<" "<<b<<" "<<ans<<endl;
	}
	return ans;
}

int main(){
	int a,b,c;
	cin>>a>>b>>c;
	cout<<powermod(a,b,c);
}

