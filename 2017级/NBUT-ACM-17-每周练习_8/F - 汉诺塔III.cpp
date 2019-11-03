#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

int main(){
	int n;
	while(cin>>n){
		long long ans=1;
		for(int i=1;i<=n;i++) ans*=3;
		cout<<ans-1<<endl;
	}
	return 0;
}
