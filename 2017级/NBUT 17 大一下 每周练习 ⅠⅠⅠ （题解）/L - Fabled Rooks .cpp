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
struct node{
	int x,y;
	int id;
}linea[5005],lineb[5005];
int x[5005],y[5005];
int vis[5005];
int cmp(node a,node b){
	if(a.y==b.y) return a.x<b.x;
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