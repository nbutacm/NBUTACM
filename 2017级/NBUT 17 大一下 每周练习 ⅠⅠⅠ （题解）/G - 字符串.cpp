#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <map>
#include <cmath>
#define FAST_IO ios::sync_with_stdio(false)
#define clr(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
const double pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 10005;

char s[1000005],p[10005];
int pre[10005];

void cal_prefix(){
	int l = strlen(p);
	pre[0] = -1;
	int k = -1,j = 0;
	while(j<=l){
		if(k==-1||p[k]==p[j]) pre[++j] = ++k;
		else k = pre[k];
	}
}

int kmp(){
	int n = strlen(s),m = strlen(p);
	int i = 0,j = 0;
	while(i<n){
		if(s[i]==p[j]&&j==m-1) return i-m+2;
		if(j==-1||s[i]==p[j]) i++,j++;
		else j = pre[j];
	}
	return -1;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int ans = 0;
		scanf("%s",s);
		scanf("%s",p);
		cal_prefix();
		printf("%d\n",kmp());
	}
	return 0;
}