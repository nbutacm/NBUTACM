//E - IP��ѯ NBUT - 1682
//== ���� ==
//��n�����䣬���䷶ΧΪx-y��ÿ���������Լ��ı�š�
//Ȼ����m��ѯ�ʣ�ѯ��ip���ڵڼ������� 

//== ��� ==
//��Ϊ���䷶Χ�ܴ����Բ���ֱ������������ʾ������ѡ��ʹ�ýṹ���¼���е�����ͱ�� 
//����ÿ��ѯ�ʣ���Ϊm*n=10^10 ֱ�ӱ���һ�������һᳬʱ
//���������ȶԽṹ���������xС����ǰ��
//������������飬���ǿ���ʹ�ö��ֲ����Ż� 



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
