#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int t,n;
int a[105][105];

int main(){
	cin>>t;
	while(t--){
		cin>>n;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				cin>>a[i][j];
			}
		}
		for(int i=n-1;i>=1;i--){
			for(int j=1;j<=i;j++){
				a[i][j]=a[i][j]+max(a[i+1][j],a[i+1][j+1]);
			}
		}
		cout<<a[1][1]<<endl;
	}
} 

 
