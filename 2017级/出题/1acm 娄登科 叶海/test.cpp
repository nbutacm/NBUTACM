#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long
const ll inf  = 0x3f3f3f3f;
const ll N = 100000+5;
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f; 
}

int o,m,n;
struct node{
	int x,y,l;
};
std::vector<node>arr;

int root[N];

int find(int x){
	return root[x]==x?x:root[x]=find(root[x]);
}

bool cmp(node a,node b){
	return a.l<b.l;
}

int main(){
	int t;
	t=read();
	while(t--){
		o=read();n=read();m=read();
		for(int i=1;i<=n;i++){
			root[i]=i;
		}
		arr.clear();
		for(int i=1;i<=m;i++){
			int x,y,l,p;
			x=read();
			y=read();
			l=read();
			p=read();
			if(o>=p){
				node temp;
				temp.x=x;
				temp.y=y;
				temp.l=l;
				arr.push_back(temp);
			}
		}
		sort(arr.begin(),arr.end(),cmp);
		int ans=0,cnt=0;
		for(int i=0;i<arr.size();i++){
			int x=find(arr[i].x);
			int y=find(arr[i].y);
			if(x!=y){
				cnt++;
				root[x]=y;
				ans+=arr[i].l;
			}
		}
		//cout<<cnt<<endl;
		if(cnt==n-1){
			cout<<"YES"<<endl;
			cout<<ans<<endl;
		}
		else{
			cout<<"NO"<<endl;
			
		}
	}
	return 0;
}