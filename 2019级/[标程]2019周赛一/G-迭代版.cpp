#include <bits/stdc++.h>
using namespace std;
long long a[100005];
#define MOD 1000000007

int main()
{
    int n;
    a[1]=2;
    a[2]=3;
    for(int i=3;i<=100000;i++)
        a[i]=(a[i-1]+a[i-2])%MOD;
    cin>>n;
    cout<<a[n]<<endl;
}
