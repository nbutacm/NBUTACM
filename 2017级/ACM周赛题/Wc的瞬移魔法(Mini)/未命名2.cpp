#include<time.h>
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
const int n=100000;
const int m=50000;
const int MAX=1000000000;
unsigned long ulrand(void) {
    return (
     (((unsigned long)rand()<<24)&0xFF000000ul)
    |(((unsigned long)rand()<<12)&0x00FFF000ul)
    |(((unsigned long)rand()    )&0x00000FFFul));
}

int a[100005];
int main(){
	freopen("data.in","w",stdout);
	srand(time(NULL));
	int t=1;
	while(t--){
		cout<<n<<" "<<m<<endl;
		for(int i=0;i<n;i++){
			a[i]=ulrand()%MAX+1;
		}
		sort(a,a+n);
		for(int i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
		
		cout<<endl;
		for(int i=0;i<m;i++){
			cout<<a[ulrand()%n+1]<<" ";
		}
		cout<<endl;
	}
	
}
