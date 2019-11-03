#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int n;
int ans=0;
int MAX=0;
int a[505][505];

int main(){
	cin>>n;
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]+=max(a[i-1][j],a[i][j-1]);
		}
	}
	cout<<a[n][n]<<endl;
} 
