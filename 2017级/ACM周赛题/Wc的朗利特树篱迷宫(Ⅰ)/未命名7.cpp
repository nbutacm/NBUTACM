#include<iostream>
using namespace std;

int main(){
	freopen("1.txt","w",stdout);
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			cout<<'*';
		}
		cout<<endl;
	}
}
