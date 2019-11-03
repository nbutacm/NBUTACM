#include<iostream>
#include<algorithm>
using namespace std;

int n;
int a[50005];

int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	int ans=0,temp=0;
	for(int i=n-1;i>=0;i--){
		if(temp+a[i]>=0) temp=0;
		else temp+=a[i];
	}
	cout<<temp*-1<<endl;
} 
