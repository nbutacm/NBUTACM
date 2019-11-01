#include<iostream>
#include<algorithm>
#include<cstring>
#include<stdio.h>
using namespace std;

int n,m;
int ans=0;
int MAX=0;
int a[1005][1005];

int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%d",&a[i][j]);
				if(a[i][j]<0) a[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				a[i][j]+=max(a[i-1][j],a[i][j-1]);
			}
		}
		printf("%d\n",a[n][m]);
	}
	
} 
