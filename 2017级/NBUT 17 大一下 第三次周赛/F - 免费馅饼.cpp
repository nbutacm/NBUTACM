#pragma comment(linker, "/STACK:1024000000,1024000000")
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

int dp[MAX][15];  //表示 第 t 秒在i位置时，所能得到的最多的馅饼数目
//ans=dp[0][5] 



int main(){
    //std::ios::sync_with_stdio(false);
	while(scanf("%d",&n)!=EOF){
		if(n==0) break;
		int t,pos;
		int max_t=-INF;
		mem(dp);
		_for(i,1,n){
			scanf("%d%d",&pos,&t);
			dp[t][pos]++;
			max_t=max(max_t,t);
		}
		__for(i,max_t-1,0){
			_for(j,0,10){
				if(j==0){
					dp[i][j]=dp[i][j]+max(dp[i+1][j],dp[i+1][j+1]);
				}
				else if(j==10){
					dp[i][j]=dp[i][j]+max(dp[i+1][j],dp[i+1][j-1]);
				}
				else{
					dp[i][j]=dp[i][j]+max(dp[i+1][j],max(dp[i+1][j-1],dp[i+1][j+1]));
				}
			}
		}
		printf("%d\n",dp[0][5]);
	}


    return 0;
}