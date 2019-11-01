
//模拟 

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
#define FAST_IO ios::sync_with_stdio(false)
#define clr(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
const double pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 10005;

int a,b,c;

int main(){
	while(cin >> a >> b >> c){
		if(a==0&&b==0){
			puts("No");
			continue;
		}
		if(b==0){
			if(c%a==0) puts("Yes");
			else puts("No");
			continue;
		}
		if(a==0){
			if(c%b==0) puts("Yes");
			else puts("No"); 
			continue;
		}
		bool flag = 0;
		for(int i=0;;i++){
			if(a*i>c) break;
			if((c-a*i)%b==0) flag = 1;
		}
		if(flag) puts("Yes");
		else puts("No");
	}
	return 0;
}

// exgcd

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



int extended_euclid(int a, int b, int &x, int &y){
    if(b == 0) // gcd(a, b) == a
    {
        x = 1;
        y = 0;
        return a;
    }
    int n = extended_euclid(b, a%b, x, y);
    int tmp = x;
    x = y;
    y = tmp - static_cast<int>(a/b)*y;
    return n;
}

int main(){
    std::ios::sync_with_stdio(false);
    int a,b,c,x,y;
    while(cin>>a>>b>>c){
    	int GCD=extended_euclid(a,b,x,y);
    	if(GCD==0) cout<<"No"<<endl;
    	else{
    		x*=c/GCD;
    		x%=(b/GCD==0?x+1:b/GCD);
    		if(x<0) x+=b/GCD;
    		if((c-a*x)>=0&&b>0&&(c-a*x)%b==0) cout<<"Yes"<<endl;
    		else cout<<"No"<<endl;
    	}
    }


    return 0;
}