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


//��Ϊ n,m,a �ķ�Χ�ڣ�1��1000000000�� ��˵��������n=m=1000000000��a=1�����������Ҫlong long 
