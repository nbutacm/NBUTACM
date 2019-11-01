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

/*
	暴力dfs
	对于每颗棋子有翻或不翻两种状态
	总共2^16种情况
*/

char pic[10][10];
int ans=INF;

void change(int x,int y){
	pic[x][y]=pic[x][y]=='b'?'w':'b';
	pic[x+1][y]=pic[x+1][y]=='b'?'w':'b';
	pic[x][y+1]=pic[x][y+1]=='b'?'w':'b';
	pic[x-1][y]=pic[x-1][y]=='b'?'w':'b';
	pic[x][y-1]=pic[x][y-1]=='b'?'w':'b';
}

bool check(){
	char p=pic[1][1];
	_for(i,1,4){
		_for(j,1,4){
			if(pic[i][j]!=p) return false;
		}
	}
	return true;
}

void dfs(int x,int y,int step){
	if(check()){
		ans=min(ans,step);
	}
	if(x<=4){
		dfs(x+y/4,y%4+1,step);
		change(x,y);
		dfs(x+y/4,y%4+1,step+1);
		change(x,y);
	}
}

int main(){
    std::ios::sync_with_stdio(false);
 	_for(i,1,4) cin>>(pic[i]+1);
 	dfs(1,1,0);
 	if(ans==INF) cout<<"Impossible"<<endl;
  	else cout<<ans<<endl;
}