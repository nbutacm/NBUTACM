#include<iostream>
#include<algorithm>
#include<string.h> 
#include<stdio.h>
using namespace std;

int n;
char s[10005];

int main(){
	while(scanf("%d",&n)!=EOF){
		getchar();
		gets(s);
		int dp[10005];      //��¼��i����ǰ�ж��ٸ��ո� 
		dp[0]=0;
		int m=1;            //�������� 
		int kong=0;
		int ans=0;
		int len=strlen(s);
		for(int i=0;i<len;i++){
			if(s[i]=='|'){
				dp[m]=kong;
				m++;
			}
			else kong++;
		}
		for(int i=n+2;i<m;i++){
			ans=max(ans,dp[i]-dp[i-1-n]);        //��������֮��Ŀո���  ����һ��ȡ���ֵ 
		}
		printf("%d\n",ans);
	} 
}
