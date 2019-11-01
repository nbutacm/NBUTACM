#include<iostream>
using namespace std;
#define ll long long

ll n;

int main(){
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	while(cin>>n){
		for(int i=1;i<=n;i++){
			ll temp=i/10,ans=i;
			while(temp){
				ans=ans*10+temp%10;
				temp/=10;
			}
			cout<<ans<<(i==n?"\n":" ");
		}
	}
}
