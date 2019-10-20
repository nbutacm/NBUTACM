#include<iostream>
using namespace std;

int main(){
    int n,m,a,sum;
    cin >> n;
	while(n-- ){
		sum = 0;
		cin >> m;
		for(int i=1 ; i <= m ;i++){
			cin >> a;
			sum += a;
		}
		cout << sum << endl;
	}
	return 0;
}

