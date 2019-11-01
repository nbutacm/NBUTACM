#include <iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int mod=1000000007;
int a[1005]={1,1,2};
int main (){
    int n;
    cin>>n;
    for(int i=3;i<=n;i++){
        a[i]=(a[i-1]+a[i-2])%mod;
    }
    cout<<a[n]<<endl;
  	return 0;
}

