#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
#define ls 2*i
#define rs 2*i+1
#define up(i,x,y) for(i=x;i<=y;i++)
#define down(i,x,y) for(i=x;i>=y;i--)
#define mem(a,x) memset(a,x,sizeof(a))
#define w(a) while(a)
#define LL long long
const double pi = acos(-1.0);
#define Len 20005
#define mod 19999997
const int INF = 0x3f3f3f3f;

int ans[10] = {6,9,6,5,5,5,5};
int t,n;
/*
题意：问放五一假能放几天，如果五一是星期一，那么9天，星期二，星期日，那么6天，否则5天
通过题意，我们得知1928年五一是星期二
思路:直接一年一年的跳就可以了
*/
int leap(int y)
{
    if(y%400==0 || (y%4==0&&y%100!=0))
        return 366;
    return 365;
}

int main()
{
    scanf("%d",&t);
    w(t--)
    {
        scanf("%d",&n);
        int d = 2,y = 1928;
        if(n==y)
        printf("%d\n",ans[d]);
        else
        {
            w(n!=y)
            {
                y++;
                d = (d+leap(y))%7;
            }
            printf("%d\n",ans[d]);
        }
    }

    return 0;
}