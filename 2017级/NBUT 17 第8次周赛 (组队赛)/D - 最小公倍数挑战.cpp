//D - 最小公倍数挑战 51Nod - 1419


// 找最大的三个数两两互质

// 根据 相邻互质 和 奇数隔一个互质 


#include<iostream>
using namespace std;

int main(){
	long long n,m;
	cin>>n;
	if(n==1)        cout<<1<<endl;
	else if(n==2)   cout<<2<<endl;
	else if(n%2==1) cout<<n*(n-1)*(n-2)<<endl;
	else{
		if(n%3==0)  cout<<(n-1)*(n-2)*(n-3)<<endl;
		else        cout<<n*(n-1)*(n-3)<<endl;
	}
	return 0;
}
