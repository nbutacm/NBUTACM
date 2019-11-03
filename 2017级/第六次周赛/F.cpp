#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
using namespace std;

int n,m,a[100005],num;

int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(a,0,sizeof(a));
		for(int i=0;i<m;i++){
			scanf("%d",&num);
			if(num<=n&&num>=1){
				a[num]=1;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0) ans++;
		}
		printf("%d\n",ans);
	}
}
