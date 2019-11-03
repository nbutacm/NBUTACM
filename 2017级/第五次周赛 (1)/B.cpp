#include<stdio.h>
#include<string.h>

int n,zero,one,ans;
char a[200005],b;

int abs(int a){
	return a>0?a:-a;
}

int main(){
	while(scanf("%d",&n)!=EOF){
		zero=one=ans=0;
		scanf("%s",a);
		for(int i=0;i<n;i++){
			if(a[i]=='0') zero++;
			else one++;
		}
		ans=zero-one;
		printf("%d\n",abs(ans));
	}
}
