//  ���3��д�� 

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


//���������ֵ��д��    ����ͬ�ඨ��   �����������������n�Ƿ����� 
 
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
