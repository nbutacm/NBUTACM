#include<cstdio>
#include<cmath>
#include<cstring>
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
#define si(n) scanf("%d",&n)
const int INF=0x3f3f3f3f;
const int MAX=1e5+5;
const int MOD=1e9+7;
map<string,int>mm;

int main(){
	//std::ios::sync_with_stdio(false);


    int t;
    cin>>t;
    while(t--)
    {
        mm.clear();
        int n;int num=0;
        cin>>n;
        while(n--)
        {
            string s;
            cin>>s;
            while(s.find("u")!=string::npos)
            {
                s.replace(s.find("u"),1,"oo");
            }
            while(s.find("kh")!=string::npos)
            {
                s.replace(s.find("kh"),2,"h");
            }
            if(mm[s]==0)mm[s]++,num++;
        }
        cout<<num<<endl;
    }
	return 0;
}