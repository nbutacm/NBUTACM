#include<stdio.h>
#include<iostream>
#include<stack>
using namespace std;

int n;
int a,b;
int ans;

int main(){
	scanf("%d",&n);
	stack<int>s;
	while(n--){
		scanf("%d%d",&a,&b);
		ans++;
		if(b==1){
			s.push(a);
		}
		else{
			while(!s.empty()){
				if(a>s.top()){
					s.pop();
					ans--;
				}
				else{
					ans--;
					break;
				}
			}
		}
	}
	printf("%d",ans);
}
