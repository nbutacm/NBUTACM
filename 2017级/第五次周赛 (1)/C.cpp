#include<stdio.h>

int min(int a,int b){
	return a>b?b:a;
}

int n,m,a,b,c;

int main(){
	scanf("%d%d%d%d",&n,&m,&a,&b);
	if(b/m>=a){                    //说明普通票便宜，全用地铁票 
		printf("%d\n",n*a);
	}
	else{                          //说明特价票便宜，大部分用特价票，最后剩下的路程再判断特价票便宜还是普通票便宜？ 
		int ans=n/m*b;
		n=n%m;
		ans+=min(n*a,b); 
		printf("%d\n",ans); 	
	}
}
