#include<bits/stdc++.h>
using namespace std;
char s[300];
int n,x;
inline void w1(int a){
    for (int i=1;i<=n;i++){
        putchar(' ');
        int t=s[i]^48;
        for (int j=1;j<=x;j++)
        putchar(a&(1<<t)?'-':' ');
        putchar(' ');putchar(' ');
    }
    putchar('\n');
}
inline void w2(int a,int b){
    for (int i=1;i<=n;i++){
        int t=s[i]^48;
        putchar(a&(1<<t)?'|':' ');
        for (int j=1;j<=x;j++) 
        putchar(' ');
        putchar(b&(1<<t)?'|':' ');
        putchar(' ');
    }
    putchar('\n');
}
int main(){
    scanf("%d%s",&x,s+1);
    n=strlen(s+1);
    w1(1005);
    for (int i=1;i<=x;i++) w2(881,927);
    w1(892);
    for (int i=1;i<=x;i++) w2(325,1019);
    w1(877);
}
