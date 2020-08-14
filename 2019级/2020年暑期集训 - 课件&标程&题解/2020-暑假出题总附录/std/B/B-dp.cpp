#include<iostream>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<set>
using namespace std;
#define goup(i,a,b) for(int i=a;i<b;i++)
#define Goup(i,a,b) for(int i=a;i<=b;i++)
#define godown(i,a,b) for(int i=a;i>b;i--)
#define Godown(i,a,b) for(int i=a;i>=b;i--)
#define Gohead(i,a) for(int i=head[a];i;i=nxt[i])
#define memsetfa(n) for(int i=0;i<=n;i++)fa[i]=i
#define memsetmin(i) memset(i,0,sizeof(i))
#define memsetmax(i) memset(i,0x3f3f3f,sizeof(i))
#define FAST_IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
typedef long long ll;
const int dir[9][2] = { {0,0},{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1} };
const int Mod = 1e9 + 7;
int n, p, q, dp[200005][2];
int main()
{
    while (cin >> n >> p >> q)
    {
        memsetmax(dp);
        dp[0][0] = dp[0][1] = 0;
        Goup(i, 1, n)
        {
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + q;
            int l = i - 1;
            while (l >= 0 && dp[l][1] + p * pow(i - l, 2)<=dp[i][0])
            {
                l--;
                dp[i][0] = dp[l + 1][1] + p * pow(i - l - 1, 2);
            }
        }
        cout << min(dp[n][0], dp[n][1]) << endl;
    }
    return 0;
}
