#include<iostream>
#include<string.h>
using namespace std;

int t,n;
int num[10];

int main(){
	cin>>t;
	while(t--){
		cin>>n;
		memset(num,0,sizeof(num));
		
		for(int i=1;i<=n;i++){
			int temp=i;
			while(temp>0){
				num[temp%10]++;
				temp/=10;
			}
		} 
		
		for(int i=0;i<=9;i++){
			if(i==0) cout<<num[i];
			else cout<<" "<<num[i];
		}
		cout<<endl;
	}
} 
