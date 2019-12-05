#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	if(n%2==1||n==2) cout<<"NO"<<endl;
	else cout<<"YES"<<endl; 
}

//就是判断两个人能不能将西瓜分成两份偶数质量的
//如果n=2，分开只能1 1 不是偶数质量 
