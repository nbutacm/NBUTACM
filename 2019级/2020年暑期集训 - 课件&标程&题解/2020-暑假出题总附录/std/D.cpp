#include<iostream>
using namespace std;
const int MAX=4*1e4+10;
int dp[MAX];
int v[110];
int w[110];
int m[110];
int main()
{
    int n,W;
    cin>>n>>W;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i]>>w[i]>>m[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=m[i];k*=2)
        {
            for(int j=W;j>=0;j--)
            {
                if(j>=k*w[i])
                {
                    dp[j]=max(dp[j],dp[j-w[i]*k]+v[i]*k);
                }else
                break;
            }
            m[i]-=k;
        }
        for(int j=W;j>=0;j--)
        {
            if(j>=m[i]*w[i])
            dp[j]=max(dp[j],dp[j-m[i]*w[i]]+m[i]*v[i]);
            else
            break;
        }
    }
    cout<<dp[W]<<endl;
    return 0;
}
