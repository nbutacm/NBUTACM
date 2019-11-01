//Codeforces 166E Tetrahedron
//题型：DP
//题解：每个点都可以从另外三个点转移过来
//dp[i][j]：代表路径为i,最后停在j顶点的方案数
//每次从各个顶点转移过来,同时取模,最终dp[n][0]即为答案

//0相当于D，ABC为123

#include <bits/stdc++.h>
using namespace std;

const int mod=1000000007;
const int N=1e7+10;
int dp[N][4];

int main(){
    int n;
    cin>>n;
    dp[0][0]=1;
    for(int k=1;k<=n;k++){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(i==j) continue;
                dp[k][i]=(dp[k][i]+dp[k-1][j])%mod;
            }
        }
    }
    cout<<dp[n][0]<<endl;
    return 0;
}
