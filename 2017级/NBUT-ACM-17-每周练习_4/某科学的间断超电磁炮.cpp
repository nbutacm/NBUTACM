#include<iostream>
#include<algorithm>
using namespace std;

int n,m;
int a[2005];

int main(){
	while(cin>>n>>m){
		for(int i=0;i<n+m;i++){
			cin>>a[i];
		}
		sort(a,a+n+m);
		for(int i=0;i<n+m;i++){
			if(i==0) cout<<a[i];
			else{
				if(a[i]==a[i-1]) continue;
				else cout<<" "<<a[i];
			}
		}
		cout<<endl;
	}
} 
