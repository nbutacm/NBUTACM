#include<stdio.h>
long long f[10000009];
int main() {
    int  a;
    scanf("%d",&a);
    for(int i=1; i<=a; i++) {
        for(int j=i; j<=a; j=j+i) {
            f[j]++;
        }
    }
    long long ans=0;
    for(int i=1; i<=a; i++) {
        ans=ans+i*f[i];
    }
    printf("%lld",ans);
}
