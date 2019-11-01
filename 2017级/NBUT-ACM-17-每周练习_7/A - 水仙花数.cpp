// 先把范围内的所有水仙花数找出来 

#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>   
#define N 1000  
int main(){  
    int i,n,a[6]={153,370,371,407,1634};  
    while(scanf("%d",&n)!=EOF){  
        for(i=0;i<=4;i++)  
            if(a[i]>=n){  
                printf("%d\n",a[i]);  
                break;  
            }  
    }  
    return 0;  
}


// 暴力判断每一个数是不是水仙花数
#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

int main(){
	int m;
	int ans=0;
	long long sum=0;
	cin>>m; 
	for (int i=m;i>0;i++){
		sum=0;
		ans=0;
		int j=i;
		int len=0;
		while(j>0){
			len++;
			j/=10;
		}
		j=i;
		while(j>0){
			ans=j%10;
			sum=sum+pow(ans,len);
			j/=10;
		}
		if (sum==i){
			cout<<i<<endl;
			break;
		}
	
	}	
	return 0;
}
