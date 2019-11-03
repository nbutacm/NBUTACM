#include<iostream>
#include<algorithm> 
#include<math.h>
using namespace std;

int t;
int n,num;

int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}

int main(){
	cin>>t;
	while(t--){
		cin>>n;
		int ans=1;
		for(int i=0;i<n;i++){
			cin>>num;
			ans=ans/gcd(ans,num)*num;
		}
		cout<<ans<<endl; 
	}
}
