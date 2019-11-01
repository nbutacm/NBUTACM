#include<iostream>
#include<algorithm>
using namespace std;

int n, a[105], MEX;

int main(){
	cin >> n >> MEX;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n);                     
	int ans = MEX ;

	for (int i = 0; i < n; i++){
		if (a[i] < 0) continue;         
		else if (a[i] < MEX) ans--;
		else if (a[i] == MEX) ans++;
		else break;
	}
	cout << ans << endl;
}

// 题目大意就是给你一组数据 你可以通过多次 加入数字或者删除数字 这两种操作  使数据中的不存在的最小非负整数为 MEX 

 
