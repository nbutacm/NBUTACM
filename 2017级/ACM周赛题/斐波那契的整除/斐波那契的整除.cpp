#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int n;

int main(){
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	while(cin>>n){
		if(n%12==0) cout<<"YES"<<endl;
		else if(n%6==0) cout<<"4"<<endl;
		else if(n%4==0) cout<<"3"<<endl;
		else cout<<"NO"<<endl;
	}
	/*long long a[105];
	a[1] = 1;
	a[2] = 1;
	cout << 1 << " " << 1 << endl;
	cout << 2 << " " << 1 << endl;
	for (int i = 3; i <= 50; i++){
		a[i] = a[i - 1] + a[i - 2];
		cout << i << " " << a[i];
		if (a[i] % 12 == 0) cout << " YES" << endl;
		else if (a[i] % 3 == 0) cout << " 3" << endl;
		else if (a[i] % 4 == 0) cout << " 4" << endl;
		else cout << " NO" << endl;
		
	}*/
}
