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

// ��Ŀ������Ǹ���һ������ �����ͨ����� �������ֻ���ɾ������ �����ֲ���  ʹ�����еĲ����ڵ���С�Ǹ�����Ϊ MEX 

 
