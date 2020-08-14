#pragma GCC oplmize(2)
#include <bits/stdc++.h>
#define ll long long
#define sc(x) scanf("%d",&x)
#define scs(x) scanf("%s",x)
#define pr(x) printf("%lld\n",x)
#define prs(x) printf("%s\n",x)
using namespace std;
const int maxn=5e5+5;
const int mod=1e9+7;
const double pi=acos(-1.0);
const double eps = 1e-8;
ll t,n,p,s[maxn],a[maxn],dp[maxn],sta[maxn];
 
int main()
{
    sc(t);
    while(t--){
        sc(n),sc(p);
        memset(dp,0,sizeof(dp));
        memset(s,0,sizeof(s));
        memset(sta,-1,sizeof(sta));
        for(int i=1;i<=n;i++){
            sc(a[i]);
            if(a[i]%p==0) dp[i]=1;
            s[i]=(s[i-1]+a[i])%p;
        }
        //sta[s[1]]=1;
        sta[0]=0;
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1];
            if(sta[s[i]]!=-1){
                dp[i]=max(dp[i],dp[sta[s[i]]]+1);
                sta[s[i]]=i;
            }
            else{
                sta[s[i]]=i;
            }
            //cout<<s[i]<<" "<<sta[s[i]]<<" "<<dp[i]<<endl;
        }
        pr(dp[n]);
    }
    return 0;
}
