#include<iostream>
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
char s[MAX];
/*  题意：给一个长度为N的S串，可以通过以下操作构造出一个T串，要求T串最小
    1.从S的头部删除一个字符，加到T的尾部
    2.从S的尾部删除一个字符，加到T的尾部
 
    不断取S的开头和末尾中较小的一个字符放到T的尾部
    如果开头的尾部的字符一样大，则继续比较它们的下一个，直到不同
 */
int main(){
    cin>>n;
    _for(i,1,n) cin>>s[i];
    int left=1,right=n;
    int cnt=0;  //每80个字符换一行
    while(left<=right){
        bool flag=false;
        int l=left,r=right;
        while(l<=r){
            if(s[l]<s[r]){
                flag=true;
                break;
            }
            if(s[l]>s[r]){
                flag=false;
                break;
            }
            if(s[l]==s[r]){
                l++;r--;
            }
        }
        if(flag==true){
            cout<<s[left];
            left++;
        }
        else{
            cout<<s[right];
            right--;
        }
        cnt++;
        if(cnt%80==0) cout<<endl;
    }
}