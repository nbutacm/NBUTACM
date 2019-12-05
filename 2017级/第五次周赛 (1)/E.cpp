#include<iostream>
using namespace std;

int n,m;

int main(){
	while(cin>>n>>m){
		if(n==0&&m==0) break;
		if(n%2==0||m%2==0) cout<<"Wonderful!"<<endl;
		else cout<<"What a pity!"<<endl;
	}
} 

//     这题可以倒着推一遍，找规律
//     http://blog.csdn.net/lttree/article/details/24836839
/*
我们设 1表示先手赢，0表示后手赢

假如 n=m=1，那么图像就为

	 0
后手赢；
 
可以推出

	 1 1            当n=2,m=2时，先手必赢 
	 0 1            当n=2,m=1时，先手必赢 
	                当n=1,m=2时，先手必赢 
	                当n=1,m=1时，后手必赢 

继而推出

	 0 1 0          当n=3,m=3时，后手必赢
	 1 1 1          当n=3,m=2时，先手必赢
	 0 1 0          当n=3,m=1时，后手必赢
	                当n=2,m=3时，先手必赢
	                当n=1,m=3时，后手必赢
再推出

	 0 1 0 1 0 1 0 
	 1 1 1 1 1 1 1 
	 0 1 0 1 0 1 0 
	 
	 
最后看出当n为偶数或者m为偶数时，先手必赢 
*/ 
