#include<time.h>
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
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
	while(t--){
		cout<<ulrand()%10000+1<<endl;
		
	}
	
}
