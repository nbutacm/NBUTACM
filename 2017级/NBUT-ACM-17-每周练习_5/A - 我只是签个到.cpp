#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	if(n%2==1||n==2) cout<<"NO"<<endl;
	else cout<<"YES"<<endl; 
}

// 题意就是问是否能将质量为n的西瓜分成两块质量均为偶数的西瓜
// 质量为奇数的西瓜绝对分不成两块质量均为偶数的西瓜，而偶数中质量为2的西瓜也分不成 
