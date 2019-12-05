#include<iostream>
#include<string.h>
using namespace std;

char a[1005];
int b[200];
int n;

int main(){
	cin>>a;
	cin>>n;
	int len=strlen(a);
	int ans=0;
	for(int i=0;i<len;i++){
		if(b[a[i]]==0){
			ans++;
			b[a[i]]=1;
		}  //ans表示字符串中有几个不同的字符 
	}	
	if(len<n) cout<<"impossible"<<endl;
	else{
		if(ans>n) cout<<0<<endl;
		else cout<<n-ans<<endl;
	}
} 
