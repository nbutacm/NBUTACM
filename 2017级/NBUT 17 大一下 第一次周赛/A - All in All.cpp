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

string a,b;

int main(){
    while(cin>>a>>b){
        int lena=a.size();
        int lenb=b.size();
        int t=0;
        _for(i,0,lenb-1){
            if(a[t]==b[i]){
                t++;
            }
        }
        if(t==lena) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}