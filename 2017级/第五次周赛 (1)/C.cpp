#include<stdio.h>

int min(int a,int b){
	return a>b?b:a;
}

int n,m,a,b,c;

int main(){
	scanf("%d%d%d%d",&n,&m,&a,&b);
	if(b/m>=a){                    //˵����ͨƱ���ˣ�ȫ�õ���Ʊ 
		printf("%d\n",n*a);
	}
	else{                          //˵���ؼ�Ʊ���ˣ��󲿷����ؼ�Ʊ�����ʣ�µ�·�����ж��ؼ�Ʊ���˻�����ͨƱ���ˣ� 
		int ans=n/m*b;
		n=n%m;
		ans+=min(n*a,b); 
		printf("%d\n",ans); 	
	}
}
