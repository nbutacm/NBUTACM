#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
const int inf=0x3f3f3f3f;
int a[4],ans=0;
int main(){
	while(~scanf("%d%d%d",&a[0],&a[1],&a[2])){
		ans=0;
		sort(a,a+3);
		int c=max(a[2]-a[0],a[2]-a[1]);
		int b=min(a[2]-a[0],a[2]-a[1]);
		ans+=b;
		c-=b;
		if(c%2==0) ans+=c/2;
		else{
			ans+=c/2+2;
		}
		printf("%d\n",ans);
	}

}
