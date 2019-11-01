#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring> 
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#define FAST_IO ios::sync_with_stdio(false)
#define mem(a) memset(a,0,sizeof(a))
using namespace std;
typedef long long ll;
const double pi = acos(-1.0);
const int INF=0x3f3f3f3f;
const int maxn=1e4+20;

/*

将数据扩大100倍处理
然后二分答案

*/

int n,k,tmp;
int a[maxn];

int main(){
    scanf("%d%d",&n,&k);
    double x;
    int m = -1;
    for(int i=1;i<=n;i++){
        scanf("%lf",&x);
        tmp = x*100;
        a[i] = tmp;
        m = max(m,tmp);
    }
    int l = 1,r = m;
    int ans = 0,mid;
    while(l<=r){
        tmp = 0;
        mid = (l+r)/2;
        for(int i=1;i<=n;i++){
            tmp += a[i]/mid;
        }
        if(tmp>=k){
            ans = max(ans,mid);
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    double res = ans/100.0;
    printf("%.2f\n",res);
    return 0;
}