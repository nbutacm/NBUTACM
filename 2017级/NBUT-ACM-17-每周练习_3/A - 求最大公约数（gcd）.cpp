#include<iostream>
using namespace std;

int a,b;

int gcd(int a,int b){            
	return b==0?a:gcd(b,a%b);
}

int main(){
	while(cin>>a>>b){
		cout<<gcd(a,b)<<endl;
	}
	return 0; 
}

//欧几里得辗转相除法
//gcd(a,b)=c 
//c 为 a,b 的最大公约数 
