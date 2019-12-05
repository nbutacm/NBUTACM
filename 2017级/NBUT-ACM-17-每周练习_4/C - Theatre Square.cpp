#include<iostream>
using namespace std;

long long n,m,a;
long long N,M;

int main(){
	cin>>n>>m>>a;
	if(n%a==0) N=n/a;
	else N=n/a+1;
	if(m%a==0) M=m/a;
	else M=m/a+1;
	cout<<N*M<<endl;
} 


//因为 n,m,a 的范围在（1，1000000000） 最极端的情况就是n=m=1000000000，a=1，这种情况需要long long 
