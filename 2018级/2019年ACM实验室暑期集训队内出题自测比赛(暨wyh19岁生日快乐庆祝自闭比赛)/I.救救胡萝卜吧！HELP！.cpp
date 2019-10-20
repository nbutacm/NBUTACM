#include<cstdio>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
const ull N=1e18;
template<typename T>
inline bool scan_d(T &ret)
{
    char c; 
    int sgn;
    if(c=getchar(),c==EOF) //EOF
        return 0; 
    while(c!='-'&&(c<'0'||c>'9'))
    {
        c=getchar();
        if(c==EOF)
            return 0;
    } 
    sgn=(c=='-')?-1:1;
    ret=(c=='-')?0:(c-'0');
    while(c=getchar(),c>='0'&&c<='9') 
        ret=ret*10+(c-'0');
    ret*=sgn;
    return 1;
}
template<typename T>
inline void out(T x) 
{
    if(x>9) 
        out(x/10);
    putchar(x%10+'0');
}
 
inline ull max(ull x,ull y,ull z,ull w)
{
    ull ans=x;
    if(y>ans) ans=y;
    if(z>ans) ans=z;
    if(w>ans) ans=w;
    return ans;
}
int main()
{
    ull a,b,c,d,aa,bb,cc,dd,e,m;
    int temp;
    while(scan_d(a))
    {
        scan_d(b);
        scan_d(c);
        scan_d(d);
        m=max(a,b,c,d);
        if(m<N)
        {
            out(a+b+c+d);
            putchar('\n');
        }
        else
        {
            aa=a%10,bb=b%10,cc=c%10,dd=d%10; 
            a=a/10,b=b/10,c=c/10,d=d/10;
            temp=aa+bb+cc+dd;
            e=temp/10;
            temp%=10;
            out(a+b+c+d+e);
            out(temp);
            putchar('\n');
        }
    }
    return 0;
}