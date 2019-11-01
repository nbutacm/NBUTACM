#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<math.h>
using namespace std;

int s;

int main(){
	cin>>s;
	for(int i=sqrt(1.0*s);i>=1;i--){
		int j=s/i;
		if(i*j==s){
			cout<<(i+j)*2<<endl;
			return 0;
		}
	}	
}



