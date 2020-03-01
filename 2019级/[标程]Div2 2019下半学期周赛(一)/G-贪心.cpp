#include <bits/stdc++.h>
#define ll long long
const int mod=1e9+7;
const int maxn=5e5+5;
using namespace std;
ll a,n,m,mi=0x3f3f3f3f,dp[maxn];

int main()
{
	cin>>n>>m;
    dp[0]=1;
    for(int i=1;i<=n;i++){
        cin>>a;
        for(int j=m;j>=0;j--){
            if(dp[j]==1){
                dp[j+a]=1;
                if(j+a>=m) mi=min(mi,j+a);
            }
        }
    }
    if(mi==0x3f3f3f3f) cout<<"-1"<<endl;
    else cout<<mi<<endl;
    return 0;
}

