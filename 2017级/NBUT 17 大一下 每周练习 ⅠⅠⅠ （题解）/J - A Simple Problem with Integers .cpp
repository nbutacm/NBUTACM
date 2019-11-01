#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define FAST_IO ios::sync_with_stdio(false)
#define clr(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
const double pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+30;

int n,m;
ll a[maxn];
struct node{
	int l,r;
	ll sum,lazy;
	void update(ll val){
		sum += (r-l+1)*val;
		lazy += val;
	}
}tr[maxn<<2];

void push_up(int pos){
	int tmp = pos<<1;
	tr[pos].sum = tr[tmp].sum+tr[tmp+1].sum;
}

void push_down(int pos){
	int tmp = pos<<1;
	ll lazy = tr[pos].lazy;
	tr[tmp].update(lazy);
	tr[tmp+1].update(lazy);
	tr[pos].lazy = 0;
}

void build(int pos,int l,int r){
	tr[pos].l = l;tr[pos].r = r;
	tr[pos].lazy = 0;
	if(l==r){
		tr[pos].sum = a[l];
		return;
	}
	int mid = (l+r)>>1,tmp = pos<<1;
	build(tmp,l,mid);
	build(tmp+1,mid+1,r);
	push_up(pos);
}

void update(int pos,int l,int r,ll val){
	int L = tr[pos].l,R = tr[pos].r;
	if(l<=L&&R<=r){
		tr[pos].update(val);
		return;
	}
	if(tr[pos].lazy) push_down(pos);
	int mid = (L+R)>>1,tmp = pos<<1;
	if(l<=mid) update(tmp,l,r,val);
	if(r>mid) update(tmp+1,l,r,val);
	push_up(pos); 
}

ll query(int pos,int l,int r){
	int L = tr[pos].l,R = tr[pos].r;
	if(l<=L&&R<=r){
		return tr[pos].sum;
	}
	if(tr[pos].lazy) push_down(pos);
	int mid = (L+R)>>1,tmp = pos<<1;
	ll ans = 0;
	if(l<=mid) ans += query(tmp,l,r);
	if(r>mid) ans += query(tmp+1,l,r);
	return ans;
}

int main(){
	FAST_IO;
	while(cin >> n >> m){
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		build(1,1,n);
		char ch;
		int l,r;
		ll val;
		while(m--){
			cin >> ch >> l >> r;
			if(ch=='Q'){
				ll ans = query(1,l,r);
				cout << ans << endl;
			}
			else{
				cin >> val;
				update(1,l,r,val);
			}
		}
	}
	return 0;
}