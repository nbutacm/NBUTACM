#include<iostream>
#include<algorithm>
using namespace std;

int n,t;
int a[105];

int main(){
	cin>>n>>t;
	for(int i=0;i<n;i++){
		cin>>a[i];
		a[i]=86400-a[i];
	}
	int ans=0,i=0;
	while(t>0){
		t-=a[i];
		ans++;
		i++;
	}
	cout<<ans<<endl;
}
