#include<stdio.h>
#include<math.h>
#include<map>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 100010
#define LL long long

/*
题意：问你能否在n个数中找到值为（a+b）的数

sort后二分查找

*/

int a[N],b[N];
int main()
{
    int i,j,n,m,t,ca=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i];
        printf("Case %d:\n",ca++);
        sort(a+1,a+1+n);
        while(m--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(binary_search(a+1,a+1+n,b[x]+b[y]))
                puts("Yes");
            else puts("No");
        }
    }
    return 0;
}