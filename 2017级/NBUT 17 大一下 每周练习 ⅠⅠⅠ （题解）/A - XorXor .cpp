#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int a[100005];
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        int sum=0;
        if(n%2==1){
            for(int i=1;i<=n;i+=2){
                sum^=a[i];
            }
        }
        cout<<sum<<endl;   
    } 
} 