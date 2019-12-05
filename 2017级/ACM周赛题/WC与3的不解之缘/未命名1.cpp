//  针对3的写法 

#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

char s[1000000+5];

int main(){
	while(scanf("%s",s)!=EOF){
		int len=strlen(s);
		int ans=0;
		for(int i=0;i<len;i++){
			ans+=s[i]-'0';
		}
		if(ans%3==0) printf("YES\n");
		else printf("NO\n");
	}
}


//针对任意数值的写法    运用同余定理   可以求任意大数关于n是否整除 
 
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

char s[1000000+5];

int main(){
	while(scanf("%s",s)!=EOF){
		int len=strlen(s);
		int ans=0;
		int n=3; 
		for(int i=0;i<len;i++){
			ans=(ans*10+s[i]-'0')%n;
		}
		if(ans%n==0) printf("YES\n");
		else printf("NO\n");
	}
} 
