#include<iostream>
using namespace std;

int t;
int a,b,c,d;

int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}

int main(){
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>d;
		int Fenzi=a*d+b*c;
		int Fenmu=b*d;
		int T=gcd(Fenzi,Fenmu);
		cout<<Fenzi/T<<" "<<Fenmu/T<<endl;
	}
} 
