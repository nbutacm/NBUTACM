#include<stdio.h>
int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF){
        if((a+b)%2==0)
        printf("%d\n",a+b);
        else
        printf("%d\n",a+b+1);
    }
}