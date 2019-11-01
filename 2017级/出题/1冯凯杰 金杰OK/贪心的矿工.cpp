#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<fstream> 
using namespace std;
int price[105][105];
int main(){
	int T;
	scanf("%d",&T);
	int N;
	int a;
	while(T--){
		scanf("%d",&N);
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				scanf("%d",&a);
				price[i][j]=a+max(price[i-1][j],price[i][j-1]);
			}
		}
		printf("%d\n",price[N][N]);	
	}
	return 0;
}
