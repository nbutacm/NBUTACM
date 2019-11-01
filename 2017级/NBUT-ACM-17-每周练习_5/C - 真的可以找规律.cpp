#include<stdio.h>
long long PowerMod(long long a,long long b,long long c)  
{  
    long long ans=1;  
    a=a%c;  
    while(b>0)  
    {  
        if(b%2==1)  
            ans=ans*a%c;  
        a=a*a%c;  
        b=b/2;  
    }  
    return ans;   
}  
int main()
{
	long long n;
	while(scanf("%lld",&n)!=EOF)
	{
		printf("%lld\n",PowerMod(n,n,10));
	}
	
 } 
 
//����ֱ�� ���� ������

//Ҳ����ͨ���ҹ���    n^m�ĸ�λ����ʵֻ��n�ĸ�λ���й� ���Ҿ�Ϊ4��һѭ��
//  ���� ��n^n%10��=��n%10��^(n%4)%10   ���n%4==0 �ͱ��  ��n%10��^(4)%10


/***************************************************************

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n,x;
	cin >> n;
	if(n%4==0){
		x=pow(n%10,4);
	}
	else{
		x=pow(n%10,n%4);
	}
	int ans=x%10;
	cout << ans << endl;
	return 0;
}

*****************************************************/ 
