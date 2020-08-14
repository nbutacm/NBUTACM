#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n,a[300],str[300],j,num;
    cin>>t;
    while(t--){
        cin>>n;j=0;
        for(int i=1;i<=n;i++)
            a[i]=0;
        for(int i=1;i<=2*n;i++){
            cin>>num;
            if(a[num]==0){
                str[j]=num;
                j++;
                a[num]=1;
            }
        }
        for(int i=0;i<n;i++)
            cout<<str[i]<<' ';
        cout<<endl;
    }
    return 0;
}
