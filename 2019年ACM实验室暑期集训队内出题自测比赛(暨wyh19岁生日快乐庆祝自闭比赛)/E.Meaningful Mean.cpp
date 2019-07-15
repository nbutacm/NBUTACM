
/*************************线段树********************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int M = 2e5 + 10;
struct TnT {
    int pos;
    ll val;
}nn[M];
struct node {
    int l , r;
    ll sum;
}T[M << 2];
bool cmp(TnT a , TnT b) {
    if(a.val == b.val) return a.pos < b.pos;
    return a.val < b.val;
}
void push_up(int i) {
    T[i].sum = T[i << 1].sum + T[(i << 1) | 1].sum;
}
void build(int i , int l , int r) {
    int mid = (l + r) >> 1;
    T[i].l = l , T[i].r = r , T[i].sum = 0;
    if(l == r) return ;
    build(i << 1 , l , mid);
    build((i << 1) | 1 , mid + 1 , r);
    push_up(i);
}
void update(int i , int pos) {
    int mid = (T[i].l + T[i].r) >> 1;
    if(T[i].l == pos && T[i].r == pos) {
        T[i].sum++;
        return ;
    }
    if(mid < pos) update((i << 1) | 1 , pos);
    else update(i << 1 , pos);
    push_up(i);
}
ll query(int i , int l , int r) {
    int mid = (T[i].l + T[i].r) >> 1;
    if(T[i].l == l && T[i].r == r) {
        return T[i].sum;
    }
    push_up(i);
    if(mid < l) return query((i << 1) | 1 , l , r);
    else if(mid >= r) return query(i << 1 , l , r);
    else {
        return query(i << 1 , l , mid) + query((i << 1) | 1 , mid + 1 , r);
    }
}
int main() {
    ll n , k , a;
    scanf("%lld%lld" ,  &n , &k);
    for(int i = 1 ; i <= n ; i++) {
        scanf("%lld" , &a);
        a -= k;
        nn[i].pos = i;
        nn[i].val = nn[i - 1].val + a;
    }
    sort(nn + 1 , nn + 1 + n , cmp);
    ll ans = 0;
    build(1 , 1 , (int)n);
    for(int i = 1 ; i <= n ; i++) {
        update(1 , nn[i].pos);
        if(nn[i].val >= 0) ans++;
        if(nn[i].pos - 1 == 0) continue;
        ans += query(1 , 1 , nn[i].pos - 1);
    }
    printf("%lld\n" , ans);
    return 0;
}


/*************************树状数组********************************************************************************/


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
const int MAXN = 2e5 + 5;
LL sum[MAXN], b[MAXN], tree[MAXN], ans;
int n, k, c; 
LL query(int d){
    LL sum1 = 0;
    while (d){
        sum1 += tree[d];
        d -=  d & - d;
    }
    return sum1;
}
inline void solve(){
    sort(b, b + n + 1);
    c = unique(b, b + n + 1) - b;
    for (int i = 0; i <= n; i++)
        sum[i] = lower_bound(b, b + c + 1, sum[i]) - b + 1;
     
}
inline void add(int d){
    while (d <= n + 10){
        tree[d]++;
        d += d & -d;
    }
}
int main(){
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++){
        int x;
        scanf("%d", &x);
        sum[i] = sum[i - 1] + x - k;
        b[i] = sum[i];
    }
    solve();
    for (int i = 0; i <= n; i++){
        ans += query(sum[i]);
        add(sum[i]);
    }
    printf("%lld\n", ans);
    return 0;
}


//或者用归并排序求逆序对
//代码不展示了