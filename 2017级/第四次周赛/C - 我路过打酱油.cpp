#include<iostream>
#include<algorithm>
using namespace std;

int cmp(int a,int b){
	return a>b;
}

int main(){
	int n,m;
	int a[10000]={0};
	int ans=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	for(int i=0;i<=n-1;i++){
		ans++;
		if(a[i]+a[n-1]<=m&&i!=n-1){
			n--;
		}
	}
	cout<<ans<<endl;
}
