#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#define ll long long
#define si1(x) scanf("%d",&x)
#define si2(x,y) scanf("%d%d",&x,&y)
#define pf(x) printf("%d\n",x)
#define pfl(x) printf("%lld\n",x)
#define mem0(a) memset(a,0,sizeof(a))
#define memI(a) memset(a,INF,sizeof(a))
#define INF 0x3f3f3f3f 
#include<map>
#include<queue>
#include<vector>
#include<sstream>
#include<stack>
#include<math.h>
#define LC(a) (a<<1)//*2 
#define RC(a) (a<<1|1)//*2+1 
#define MID(a,b) ((a+b)>>1)//(a+b)/2  
#include<iomanip>
using namespace std;
const int N = 1e4+5; 
int t,n,m,x,flag;
int dj[N],fa[N];
void init(){
	flag=1;
	for(int i=1;i<=10000;i++){
		fa[i]=i;
	}
	mem0(dj);
} 
int find(int x){
	return fa[x]==x?x:fa[x]==find(fa[x]);
}
void unio(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy) ;
	 fa[fx]=fy;
}
int main(){
	si1(t);
	while(t--){
		init();
		si2(n,m);si1(x);
		for(int i=1;i<=n;i++){
			si1(dj[i]);
		}
		int from,to;
		while(m--){
			si2(from,to);
			unio(to,from);
		}		
		for(int i=1;i<=n;i++){
			if(fa[i]!=1){
				flag=0;
			}
			//cout<<fa[i]<<endl;
		}
		if(flag){
			for(int i=1;i<=n;i++){
				//cout<<dj[i]<<endl;
				if(dj[i]-3>x){
					flag=0;
					break;
				}
			}
		}
		if(flag) cout<<"WaiMai"<<endl;
		else cout<<"ShiTang"<<endl; 
	}
	return 0;	
}
