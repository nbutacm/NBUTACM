#include<cstdio>
#include<cmath>
#include<string.h>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define pi acos(-1)
#define eps 1e-10
#define mem(x) memset(x,0,sizeof(x))
#define _for(x,y,z) for(int (x)=(y);(x)<=(z);(x)++)
#define __for(x,y,z) for(int (x)=(y);(x)>=(z);(x)--)
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll powmod(ll a,ll b,ll MOD)
{ll ans=1;while(b){if(b%2)ans=ans*a%MOD;a=a*a%MOD;b/=2;}return ans;}

//用set统计有多少不同的数
//map标记该数是否出现过
//然后设置 l，r 从头扫描到尾，
// 如果不同的数小于num个，r++
// 如果不同的数有num个，检查l位置的数是否只出现一次，记录min（ans，r-l+1），否则l++
//
//

const int inf=0x3f3f3f3f;
const int MAX=100005;
const int MOD=1e9+7;
int a[1000009];
map<int,int>mmm;
set<int>t;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]),t.insert(a[i]);
    int num=t.size();
    int l=0,r=0,ci=0,ans=inf;
    while(1)
    {
        while(r<n&&ci<num)
        {
            if(mmm[a[r++]]++==0)ci++;
        }
        if(ci<num)break;
        ans=min(ans,r-l);
        if(--mmm[a[l++]]==0)ci--;
    }
    cout<<ans<<endl;


    return 0;
}