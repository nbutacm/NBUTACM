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
 
//可以直接 暴力 快速幂

//也可以通过找规律    n^m的个位数其实只和n的个位数有关 而且均为4个一循环
//  所以 （n^n%10）=（n%10）^(n%4)%10   如果n%4==0 就变成  （n%10）^(4)%10


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
