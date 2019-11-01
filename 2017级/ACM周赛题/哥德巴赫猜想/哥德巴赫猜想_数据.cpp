#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;

int a,b;

unsigned long ulrand(void) {
    return (
     (((unsigned long)rand()<<24)&0xFF000000ul)
    |(((unsigned long)rand()<<12)&0x00FFF000ul)
    |(((unsigned long)rand()    )&0x00000FFFul));
}

int main(){
	srand((unsigned int)time(0));
	freopen("data.in","w",stdout);
	
	int t=100;
	while(t--){
		while(1){
			a=ulrand()%10000+1;
			if(a>=6&&a%2==0) break;
		}
		cout<<a<<endl;
	}
}
