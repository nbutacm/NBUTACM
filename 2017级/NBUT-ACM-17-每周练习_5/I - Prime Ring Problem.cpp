#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

int n;
int a[25];
int vis[25];

bool isprime(int n){
	if(n==1||n==0) return false;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0) return false;
	}
	return true;
}

void dfs(int num,int n){
	if(num==n){
		if(isprime(a[1]+a[n])==true){
			for(int i=1;i<=n;i++){
				if(i==1) cout<<a[i];
				else cout<<" "<<a[i];
			}
			cout<<endl;
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0&&isprime(i+a[num])==true){
			vis[i]=1;
			a[num+1]=i;
			dfs(num+1,n);
			vis[i]=0;
		}
	}
}

int main(){
	int CASE=1;
	while(cin>>n){
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		cout<<"Case "<<CASE++<<":"<<endl;
		vis[1]=1;
		a[1]=1;
		dfs(1,n);
		cout<<endl;
	}
} 
