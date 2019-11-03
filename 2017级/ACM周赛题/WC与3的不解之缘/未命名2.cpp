#include<ctime>
#include<stdlib.h> 
#include<iostream>
using namespace std;

unsigned long ulrand(void) {
    return (
     (((unsigned long)rand()<<24)&0xFF000000ul)
    |(((unsigned long)rand()<<12)&0x00FFF000ul)
    |(((unsigned long)rand()    )&0x00000FFFul));
}


int main(){
	freopen("data.in","w",stdout);
	srand(time(NULL));
	int t=5;
	int a=10;
	while(t--){
		cout<<1;
		for(int i=1;i<a;i++){
			cout<<ulrand()%10;
		}
		cout<<endl;
		a*=10;
	}
	
}
