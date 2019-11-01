#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#include<stdio.h>
#include<vector>
using namespace std;

int n;
int a[50005];

struct cmp{  
     bool operator ()(long long x,long long y)  {  
        return x > y;//小的优先级高  
    }  
};  

int main(){
	while(scanf("%d",&n)!=EOF){
		memset(a,0,sizeof(a));
		
		priority_queue<int,vector<int>, cmp>q;              //优先队列模拟  
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			q.push(a[i]);
		}
		
		long long ans=0;
		while(q.size()>1){
			long long m1=q.top();q.pop();
			long long m2=q.top();q.pop();
			ans+=m1+m2;
			q.push(m1+m2);
		}
		printf("%d\n",ans);
	}
}
