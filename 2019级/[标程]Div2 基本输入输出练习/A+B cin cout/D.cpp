#include<iostream>
using namespace std;

int main(){
    int n,a,sum;
	while(cin >> n && n != 0 ){
		sum = 0;
		for(int i=1 ; i <= n ;i++){
			cin >> a;
			sum += a;
		}
		cout << sum << endl;
	}
	return 0;
}

