#include<iostream>

using namespace std;

int n, a[2005], b[2005];

int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	for (int i = 0; i < n; i++){
		cin >> b[i];
	}
	cout << "Karen" << endl;
}


// 题意：从X数组中选择一个数，从Y数组中选择一个数 
//      将这两个数进行异或操作得到一个新的数  即 N=X^Y   这样为pair（X，Y） 
//      如果X数组或者Y数组中存在N  则ans+1 
//     如果ans为偶数 则Karen获胜 输出Karen
//     否则 为Koyomi获胜 输出Koyomi

//    如果（X，Y）成立 那么（Y，X）也成立 所以ans必定为偶数 所以一定是Karen获胜 
