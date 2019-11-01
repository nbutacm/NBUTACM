#include<iostream>
#include<cmath>
#include<stdio.h>
#include<set>
#include<map>
#include<string.h>
#include<queue>
#include<cmath>
#include<algorithm>
#define INF 0x3f3f3f3f
#define _f(x,y,z) for(int (x)=(y);(x)<=(z);(x)++)
#define __f(x,y,z) for(int (x)=(y);(x)>=(z);(x)--)
const int MAXN=2e6+100;
typedef long long ll;
using namespace std;
#define PI acos(-1)
int a[MAXN];

template <class T>
inline void scan_d(T &ret) 
{
    char c; 
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    { 
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}
int main(){
	int n,a,b;
	while(~scanf("%d",&n)){
		scan_d(a);
		scan_d(b);
		int cnt_sui=0,cnt_fa=0;
		_f(i,1,n){
			int aa,bb,cc;
			scan_d(aa);
			scan_d(bb);
			scan_d(cc);
			if(aa==1&&bb==1&&cc==1) cnt_fa++;
			if(aa==0&&bb==0&&cc==0) cnt_sui++;
		}
		int e=n-cnt_sui-cnt_fa;
		a-=cnt_sui;
		b-=cnt_fa;
		int flag=1;
		if(a>0){
			e-=a;
			if(e<0) flag=0;
		}
		if(b>0){
			e-=b;
			if(e<0) flag=0;
		}
		if(flag) printf("YES\n");
		else printf("NO\n");	
	}
	return 0;
}