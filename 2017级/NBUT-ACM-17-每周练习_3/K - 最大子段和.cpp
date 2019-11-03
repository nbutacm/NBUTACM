#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;

int n;
long long a;
int main(){
	while(~scanf("%d",&n)){
		long long ans=0,MAX=0;
		for(int i=0;i<n;i++){
			scanf("%lld",&a);
			if((ans+a)<=0){
				ans=0;
			}
			else{
				ans+=a;
			}
			MAX=max(ans,MAX);
		}
		printf("%lld\n",MAX);
	}
}
