//#pragma GCC oplmize(2)
#include <bits/stdc++.h>
using namespace std;
int k;
char a[1000];
inline void le(int k){
    for(int j=1;j<=k+1;j++) printf(" ");
    printf("| ");
}
inline void ri(int k){
    printf("|");
    for(int j=1;j<=k+2;j++) printf(" ");
}
inline void mi(int k){
    printf("|");
    for(int j=1;j<=k;j++) printf(" ");
    printf("| ");
}
inline void kong(int k){
    for(int j=1;j<=k+3;j++) printf(" ");
}
inline void heng(int k){
    printf(" ");
    for(int j=1;j<=k;j++) printf("-");
    printf("  ");
}
int main()
{
    scanf("%d",&k);
    scanf("%s",a);
    for(int i=0;i<2*k+3;i++)
    {
        for(int o=0;o<strlen(a);o++){
            if((a[o]=='2' || a[o]=='3' || a[o]=='5' || a[o]=='6' || a[o]=='8' || a[o]=='9') && (i==0 || i==2*k+2 || i==k+1)){
                heng(k);
            }
            else if((a[o]=='2' || a[o]=='3' || a[o]=='5' || a[o]=='6' || a[o]=='8' || a[o]=='9')){
                if(a[o]=='2'){
                    if(i<k+1) le(k);
                    if(i>k+1) ri(k);
                }
                else if(a[o]=='3') le(k);
                else if(a[o]=='5'){
                    if(i>k+1) le(k);
                    if(i<k+1) ri(k);
                }
                else if(a[o]=='6'){
                    if(i<k+1) ri(k);
                    if(i>k+1) mi(k);
                }
                else if(a[o]=='8') mi(k);
                else{
                    if(i>k+1) le(k);
                    if(i<k+1) mi(k);
                }
            }
            if(a[o]=='0' && (i==0 || i==2*k+2)) heng(k);
            else if(a[o]=='0' && i==k+1) kong(k);
            else if(a[o]=='0') mi(k);
            if(a[o]=='1' && (i==0 || i==2*k+2 || i==k+1)) kong(k);
            else if(a[o]=='1') le(k);
            if(a[o]=='4' && (i==0 || i==2*k+2)) kong(k);
            else if(a[o]=='4' && i==k+1) heng(k);
            else if(a[o]=='4'){
                if(i==2*k+2) kong(k);
                else if(i>k+1) le(k);
                else if(i<k+1) mi(k);
            }
            if(a[o]=='7' && (i==k+1 || i==2*k+2)) kong(k);
            else if(a[o]=='7' && i==0) heng(k);
            else if(a[o]=='7') le(k);
        }
        printf("\n");
    }
    return 0;
}
