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

//ŷ�����շת�����
//gcd(a,b)=c 
//c Ϊ a,b �����Լ�� 
