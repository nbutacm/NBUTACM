#include<iostream>
using namespace std;
int main(){
	int t,a,b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		if(a%(b+1)==0) cout<<'B'<<endl;
		else cout<<'A'<<endl;
	}
	return 0;
}

//最少拿1个,最多拿b个,所以如果a是(b+1)的倍数,那么无论先手取多少,后手就一定可以凑出(1+b),最后一个一定是后手的 


//关于博弈基础知识的总结：巴什博弈（Bash Game）、尼姆博奕（Nim Game）、威佐夫博奕（Wythoff Game）。 
