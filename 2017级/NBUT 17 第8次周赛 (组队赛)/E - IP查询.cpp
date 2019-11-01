//E - IP查询 NBUT - 1682
//== 题意 ==
//有n个区间，区间范围为x-y，每个区间有自己的编号。
//然后有m次询问，询问ip属于第几个区间 

//== 题解 ==
//因为区间范围很大，所以不能直接用数组来表示，我们选择使用结构体记录城市的区间和编号 
//对于每次询问，因为m*n=10^10 直接暴力一个个查找会超时
//所以我们先对结构体进行排序，x小的在前面
//对于有序的数组，我们可以使用二分查找优化 



#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;


struct node{
	int l,r;
	int id;
}dp[MAXN];

int cmp(node a,node b){
	return a.l<b.l; 
}

int t;
int n,m;
int x,y,id,ip;
bool flag;

int main(){
	scanf("%d",&t);
	while(t--){
		memset(dp,0,sizeof(dp));
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%lld%lld%lld",&x,&y,&id);
			dp[i].l=x,dp[i].r=y,dp[i].id=id;
		}
		sort(dp,dp+n,cmp);
		scanf("%d",&m);
		while(m--){
			flag=false;
			scanf("%lld",&ip);
			int l=0,r=n;
			int mid;
			int ans;
			while(l<=r){
				mid=(l+r)/2;
				//cout<<0<<endl;
				if(dp[mid].l<=ip){
					if(dp[mid].r>=ip){
						ans=dp[mid].id;
						flag=true;
						break;
					}
					else{
						l=mid+1;
					}
				}
				else if(dp[mid].l>ip){
					r=mid-1;
				}
			}
			if(flag==false) printf("-1\n");
			else printf("%lld\n",ans);
		}
	}
}
