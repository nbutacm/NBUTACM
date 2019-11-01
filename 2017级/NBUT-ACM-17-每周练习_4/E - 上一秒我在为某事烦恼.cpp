#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;

int a[305];
int vis[305];

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		bool flag=true;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n-1;i++){
			m=abs(a[i]-a[i+1]);
			if(m>=1&&m<=n-1&&vis[m]==0){
				vis[m]++;
			}
			else{
				flag=false;
				break;
			}
		}
		if(flag==true) cout<<"Jolly"<<endl;
		else cout<<"Not jolly"<<endl;
	}
}
