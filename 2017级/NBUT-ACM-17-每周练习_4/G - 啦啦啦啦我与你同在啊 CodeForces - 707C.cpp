#include<iostream>
using namespace std;

int main(){
	long long n;
	cin>>n;
	if(n==1||n==2) cout<<-1<<endl;
	else{
		if(n*n%2==1){
			cout<<(n*n+1)/2<<" "<<((n*n-1)/2)<<endl;
		}
		else{
			cout<<(n*n/4)+1<<" "<<(n*n/4)-1<<endl;
		}
	}
}


// a^2-b^2=n^2
// (a+b)(a-b)=n^2
// if(n^2%2==1) a-b=1 a+b=n^2  a=(n^2+1)/2 b=(n^2-1)/2;
//if(n^2%2==0)  a-b=2 a+b=(n^2)/2   a=(n^2/4)+1  b=(n^2/4)-1
