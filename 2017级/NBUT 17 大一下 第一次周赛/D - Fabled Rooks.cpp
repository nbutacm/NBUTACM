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

/*

题意：在n*n棋盘上放n辆车，使得任意两辆车不相互攻击，且第i辆车在一个给定的矩形之内。

这道题利用贪心法，由于横坐标和纵坐标没有任何关系，因此可以分别处理。对于横坐标或纵坐标，贪心策略是：先按照区间右端点从小到大排序，若相同，再按照区间左端点从大到小排序，保证这种情况下长度短的在前，长的在后；每次都从区间的左端点出发，如果该位置已经被占据，则继续向后移动，如果移动到超出了区间右端点，则无解。
*/

int n;
struct node{
	int x,y;
	int id;
}linea[5005],lineb[5005];
int x[5005],y[5005];
int vis[5005];

int cmp(node a,node b){    //y小的在前面，y相同x小的在前面；
	if(a.y==b.y){
		return a.x<b.x;
	}
	return a.y<b.y;
}

bool match(node a[],int ans[]){
	sort(a+1,a+1+n,cmp);
	mem(vis);
	_for(i,1,n){
		bool flag=false;
		_for(j,a[i].x,a[i].y){
			if(vis[j]==0){
				vis[j]=1;
				ans[a[i].id]=j;
				flag=true;
				break;
			}
		}
		if(flag==false) return false;
	}
	return true;
}

int main(){
    std::ios::sync_with_stdio(false);
    while(cin>>n,n){
    	int lx,ly,rx,ry;
    	_for(i,1,n){
    		cin>>lx>>ly>>rx>>ry;
    		linea[i].x=lx;linea[i].y=rx;
    		lineb[i].x=ly;lineb[i].y=ry;
    		linea[i].id=lineb[i].id=i;
    	}
    	if(match(linea,x)&&match(lineb,y)){
    		_for(i,1,n){
	    		cout<<x[i]<<" "<<y[i]<<endl;
	    	}
    	}
    	else{
    		cout<<"IMPOSSIBLE"<<endl;
    	}
    }
    return 0;
}