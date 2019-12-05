//C - Night at the Museum
//== 题意 ==
//通过转动转盘打印字符串，求最少转动次数

//== 题解 ==
//转动转盘只有两个方向，向左或向右，所以每次累加起点字符到目标字符的较小值即可 
//ps：转盘一开始一定在a 

#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

char a[105];
int sum;

int main(){
	scanf("%s",a);
	sum=0;
	char flag='a';
	for(int i=0;i<strlen(a);i++){
		sum=sum+min(abs(flag-a[i]),26-abs(flag-a[i]));
		flag=a[i];
	}
	printf("%d",sum);
	
}
