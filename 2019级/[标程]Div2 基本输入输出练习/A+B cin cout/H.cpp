#include<iostream>
using namespace std;

int main(){
    int n,m,sum,a;
    cin >> n;
	while(n--){
		sum= 0;
		cin >> m;
		for(int i=1 ; i <= m ; i++){
			cin >> a;
			sum+=a;
		}
		if(n != 0 ) cout << sum << endl << endl;
		else cout << sum << endl ;
	}
	return 0;
}

