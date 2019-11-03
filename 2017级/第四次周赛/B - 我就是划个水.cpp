#include<iostream>
using namespace std;
const long long MOD=1000000007;

long long n;

long long PowerMod(long long a,long long b,long long c){
	long long ans=1;
	a=a%c;
	while(b){
		if(b%2==1) ans=ans*a%c;
		a=a*a%c;
		b=b/2;
	}
	return ans;
}

int main(){
	while(cin>>n){
		cout<<PowerMod(2,n*n-1,MOD)<<endl;
	}
} 
