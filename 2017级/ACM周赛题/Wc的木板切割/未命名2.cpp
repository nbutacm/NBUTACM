#include<time.h>
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
const int n=1000;
const int m=100;
 
unsigned long ulrand(void) {
    return (
     (((unsigned long)rand()<<24)&0xFF000000ul)
    |(((unsigned long)rand()<<12)&0x00FFF000ul)
    |(((unsigned long)rand()    )&0x00000FFFul));
}

long long a[100000+5];

int main(){
	freopen("data.in","w",stdout);
	srand(time(NULL));
	int t=10;
	while(t--){
		memset(a,0,sizeof(a));
		cout<<n<<endl;
		for(int i=0;i<n;i++){
			a[i]=ulrand()%m+1;
		}
		for(int i=0;i<n;i++){
			if(i==0) cout<<a[i];
			else cout<<" "<<a[i];
		}
		cout<<endl;
	}
	
}
