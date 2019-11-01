#include <iostream>  
using namespace std;    
#define ll long long 
ll a[2018],b[2018];  
int main(){
    //freopen("/Users/cccccccccchy/compare/论n和m范围内有多少对ab相乘为2018的倍数.in","r",stdin);  
    //freopen("/Users/cccccccccchy/compare/论n和m范围内有多少对ab相乘为2018的倍数.out","w",stdout);
    ll t,n,m,ans;
    cin>>t;
    while(t--){
        cin>>n>>m;  
        ans=0;  
        for(int i=0;i<2018;i++){  
            a[i]=n/2018;  
            b[i]=m/2018;  
        }  
        for(int i=1;i<=n%2018;i++){  
            a[i]++;  
        }  
        for(int i=1;i<=m%2018;i++){  
            b[i]++;  
        }  
        for(int i=0;i<2018;i++){  
            for(int j=0;j<2018;j++){  
                if((i*j)%2018==0){  
                    ans+=a[i]*b[j];  
                }  
            }  
        }  
        cout<<ans<<endl;  
    }  
    return 0;  
}  