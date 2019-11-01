#include<iostream>
#include<algorithm> 
#include<math.h>
#include<string.h>
using namespace std;

int n;
int a[10];

int main(){
	cin>>n;
	for(int i=n+1;;i++){
		memset(a,0,sizeof(a));
		int m=i;
		bool flag=true;
		while(m>0){
			int t=m%10;
			if(a[t]==0){
				a[t]=1;
			}
			else{
				flag=false;
				break;
			}
			m=m/10;
		}
		if(flag==true){
			cout<<i<<endl;
			break;
		}
	}
}
