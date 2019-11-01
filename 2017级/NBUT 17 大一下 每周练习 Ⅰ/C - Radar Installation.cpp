#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define PI acos(-1)
#define eps 1e-10
#define mem(x) memset(x,0,sizeof(x))
#define _for(x,y,z) for(int (x)=(y);(x)<=(z);(x)++)
#define __for(x,y,z) for(int (x)=(y);(x)>=(z);(x)--)
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll powmod(ll a,ll b,ll MOD){ll ans=1;while(b){if(b%2)ans=ans*a%MOD;a=a*a%MOD;b/=2;}return ans;}

const int INF=0x3f3f3f3f;
const int MAX=1e5+5;
const int MOD=1e9+7;

int n;
double d;
struct node{
	double x,y;
}a[1005];
double b[1005];
int tot;
int CASE;
int cmp(node a,node b){
	double dxa=sqrt(d*d-a.y*a.y);
	double dxb=sqrt(d*d-b.y*b.y);
	return a.x+dxa<b.x+dxb;
}

bool check(int x,int pos){
	return (a[x].y*a[x].y+(a[x].x-b[pos])*(a[x].x-b[pos]))<=d*d;
}

int main(){
    //std::ios::sync_with_stdio(false);
    while(scanf("%d%lf",&n,&d)!=EOF){
    	if(n==0&&d==0) break;
    	mem(a);
    	mem(b);
    	tot=1;
    	bool flag=true;
    	_for(i,1,n){
    		scanf("%lf%lf",&a[i].x,&a[i].y);
    		if(a[i].y>d){
    			flag=false;
    		}	
    	} 
    	sort(a+1,a+1+n,cmp);
    	double dx=sqrt(d*d-a[1].y*a[1].y);
    	b[tot]=a[1].x+dx;
    	_for(i,2,n){
    		if(!check(i,tot)){
    			tot++;
    			double dx=sqrt(d*d-a[i].y*a[i].y);
    			b[tot]=a[i].x+dx;
    		}
    	}
    	if(!flag) tot=-1;
    	printf("Case %d: %d\n",++CASE,tot);
    }
}


／／／／／／／／／／／／／／／／／／／／／／／／／／／／／／／／／／／／／／／／／／／

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
template< typename T > inline void read(T &x) {
    static bool fr_f; static char fr_ch;
    fr_f=0; x=0; fr_ch=getchar();
    while(fr_ch<'0' || '9'<fr_ch) {if(fr_ch=='-') fr_f=1; fr_ch=getchar();}
    while('0'<=fr_ch && fr_ch<='9') {x=(x<<1)+(x<<3)+fr_ch-'0'; fr_ch=getchar();}
    if(fr_f) x=-x;
}
const int inf=-0x3f3f3f3f;
const int MAX=100005;
const int MOD=1e9+7;
struct node{
double x,y;
double l,r;
}a[1009];

int cmp(node a,node b)
{
    return a.l<b.l;
}
int main()
{
    int n,flag=1;double d;
    while(flag)
    {   int ff=1;
        scanf("%d%lf",&n,&d);
        if(n==0&&d==0)return 0;
       for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",&a[i].x,&a[i].y);if(a[i].y>d||-a[i].y>d||d<0)ff=0;
            a[i].l=a[i].x-sqrt(d*d-a[i].y*a[i].y);
            a[i].r=a[i].x+sqrt(d*d-a[i].y*a[i].y);
        }
        sort(a,a+n,cmp);double l=a[0].l,r=a[0].r,o=1;
        for(int i=1;i<n;i++)
        {
            if(r>=a[i].r){l=a[i].l,r=a[i].r;}
            else if(r>=a[i].l)l=a[i].l;
            else  {
                o++;
                l=a[i].l,r=a[i].r;
            }

        }
        if(!ff)cout<<"Case "<<flag++<<": "<<-1<<endl;
        else cout<<"Case "<<flag++<<": "<<o<<endl;
    }



    return 0;
}