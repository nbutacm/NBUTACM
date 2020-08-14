#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int a[105];
int b[55];
int main(){
     int t;
     cin>>t;
     while(t--){
        int n;
        cin>>n;
        memset(b,0,sizeof(b)); 
        for(int i=1;i<=2*n;i++){
            cin>>a[i];
            if(b[a[i]]==0)
            {   b[a[i]]=1;
                cout<<a[i]<<" "; 
             }
         }
         cout<<endl;
          
     }
      
     
}
