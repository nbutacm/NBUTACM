//C - Night at the Museum
//== ���� ==
//ͨ��ת��ת�̴�ӡ�ַ�����������ת������

//== ��� ==
//ת��ת��ֻ������������������ң�����ÿ���ۼ�����ַ���Ŀ���ַ��Ľ�Сֵ���� 
//ps��ת��һ��ʼһ����a 

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
