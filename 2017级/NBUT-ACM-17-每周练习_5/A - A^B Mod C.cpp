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
    long long a,b,c;  
    scanf("%lld%lld%lld",&a,&b,&c);  
    a=PowerMod(a,b,c);  
    printf("%lld\n",a);  
    return 0;  
}

//快速幂 模板题 
