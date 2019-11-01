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

int t,a,b,c;

struct node
{
    char name[105];
    int num;
}s[3][105];

int cmp(node a,node b)
{
    return a.num<b.num;
}

int main()
{
    int i,j,k;
    scanf("%d",&t);
    w(t--)
    {
        scanf("%d%d%d",&a,&b,&c);
        up(i,0,a-1)
        scanf("%s%d",s[0][i].name,&s[0][i].num);
        up(i,0,b-1)
        scanf("%s%d",s[1][i].name,&s[1][i].num);
        up(i,0,c-1)
        scanf("%s%d",s[2][i].name,&s[2][i].num);
        sort(s[0],s[0]+a,cmp);
        sort(s[1],s[1]+b,cmp);
        sort(s[2],s[2]+c,cmp);
        int ans=s[0][a/2].num+s[1][b/2].num+s[2][c/2].num;
        printf("%d %s %s %s\n",ans,s[0][a/2].name,s[1][b/2].name,s[2][c/2].name);
    }

    return 0;
}