#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

//正方形一定是以三块木头的最长边为边
//然后判断三个木头的面积和是否等于正方形面积

int main(){
	int a[6];
	while(~scanf("%d%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5])){
		int mx=0;
		for(int i=0;i<6;i++) mx=max(mx,a[i]);
		if(mx*mx==a[0]*a[1]+a[2]*a[3]+a[4]*a[5]) printf("YES\n");
		else printf("NO\n");
	}
	return 0; 
}