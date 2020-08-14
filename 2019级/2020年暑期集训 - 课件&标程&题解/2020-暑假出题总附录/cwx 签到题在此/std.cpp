#include<iostream>
using namespace std;
long long f[10000009];
int main(){
	for(int i=1;i<=10000007;i++){
		for(int j=i;j<=10000007;j=j+i){
			f[j]++;
		}
	}
	int a;
	cin>>a;
	long long ans=0;
	for(int i=1;i<=a;i++){
		ans=ans+i*f[i];
	}
	cout<<ans<<endl;
	return 0;
}

