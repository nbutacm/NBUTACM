#include<iostream>
using namespace std;

int main(){
	int t;
	int n,m;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0;;i++){
			int j=n-i;
			if((i*4)+(j*2)==m){
				cout<<i<<" "<<j<<endl;
				break;
			}
		}
	}
} 
