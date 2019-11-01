#include<iostream>
#include<queue>
#include<string.h>
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

int t;
int a,b;
int ans;

/*
先打个素数表
然后bfs
将素数拆成四位数，给次改变其中一位数，使其成为一个新的素数，进入队列，直到找到目标素数
*/


bool isprime[10000];

bool check(int n){
    if(n==1||n==0) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}

void init(){
    _for(i,1000,9999){
        if(check(i)) isprime[i]=true;
    }
}

struct node{
    int num,step;
};

int vis[10000];

void bfs(int a,int b){
    queue<node>q;
    memset(vis,0,sizeof(vis));
    vis[a]=1;
    node u;
    u.num=a;
    u.step=0;
    q.push(u);
    while(!q.empty()){
        node v=q.front();
        q.pop();
        if(v.num==b){
            ans=v.step;
            break;
        }
        int a[5];
        a[1]=v.num/1000;
        a[2]=v.num/100%10;
        a[3]=v.num/10%10;
        a[4]=v.num%10;
        node w;
        w.step=v.step+1;
        _for(i,1,4){
            int t=a[i];
            _for(j,0,9){
                a[i]=j;
                w.num=a[1]*1000+a[2]*100+a[3]*10+a[4];
                if(w.num>=1000 && w.num<=9999 && isprime[w.num]==true && vis[w.num]==0){
                    vis[w.num]=1;
                    q.push(w);
                }
            }
            a[i]=t;
        }
    }
}

int main(){
    init();
    cin>>t;
    while(t--){
        cin>>a>>b;
        ans=-1;
        bfs(a,b);
        if(ans==-1) cout<<"Impossible"<<endl;
        else cout<<ans<<endl;
    }
}