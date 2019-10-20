#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include <cstdio>
#include <cctype>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#define fi first
#define se second
#define MP make_pair
#define P pair<int, int>
#define PLL pair<ll, ll>
#define Sca(x) scanf("%d", &x)
#define Sca2(x, y) scanf("%d%d", &x, &y)
#define Sca3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define Scl(x) scanf("%lld", &x)
#define Scl2(x, y) scanf("%lld%lld", &x, &y)
#define Scl3(x, y, z) scanf("%lld%lld%lld", &x, &y, &z)
#define Pri(x) printf("%d\n", x)
#define Prl(x) printf("%lld\n", x)
#define For(i, x, y) \
  for (int i = x; i <= y; i++)
#define _For(i, x, y) \
  for (int i = x; i >= y; i--)
#define FAST_IO std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long
const int INF   = 0x3f3f3f3f;
const ll  INFL  = 0x3f3f3f3f3f3f3f3f;
const double Pi = acos(-1.0);
using namespace std;
template<class T>void tomax(T& a, T b) {
  a = max(a, b);
}

template<class T>void tomin(T& a, T b) {
  a = min(a, b);
}

const int N = 5e5 + 5;
struct Segt {
        #define lc (p << 1)
        #define rc (p << 1 | 1)
        #define MID (tree[p].l + tree[p].r) >> 1
  struct Tree {
    int l, r;
    int val;
  } tree[N << 2 | 1];
  void pushdown(int p) {
    tree[p].val = max(tree[lc].val, tree[rc].val);
  }

  void build(int l, int r, int p) {
    tree[p] = Tree{ l, r, 0 };

    if (l == r) return;

    int mid = MID;

    if (l <= mid) build(l, mid, lc);

    if (r > mid) build(mid + 1, r, rc);
  }

  void updata(int pos, int p, int val) {
    if ((tree[p].l == pos) && (tree[p].r == pos)) {
      tomax(tree[p].val, val);
      return;
    }
    int mid = MID;

    if (pos <= mid) updata(pos, lc, val);

    if (pos > mid) updata(pos, rc, val);
    pushdown(p);
  }

  int getmax(int l, int r, int p) {
    if (l > r) return 0;

    if ((tree[p].l >= l) && (tree[p].r <= r)) return tree[p].val;

    int maxx = 0;
    int mid  = MID;

    if (l <= mid) tomax(maxx, getmax(l, r, lc));

    if (r > mid) tomax(maxx, getmax(l, r, rc));
    return maxx;
  }
} t;
struct Data {
  int a, b, c;
}   num[N];
int tmp[N];

bool cmp(Data one, Data tow) {
  return one.a > tow.a;
}

int discrete(int n) {
  sort(tmp + 1, tmp + 1 + n);
  return unique(tmp + 1, tmp + 1 + n) - tmp;
}

int main() {
  int n; Sca(n);

  For(i, 1, n) Sca(num[i].a);
  For(i, 1, n) {
    Sca(num[i].b); tmp[i] = num[i].b;
  }
  For(i, 1, n) Sca(num[i].c);
  sort(num + 1, num + 1 + n, cmp);
  int lenb = discrete(n) - 1;
  For(i, 1, n) num[i].b = lower_bound(tmp + 1, tmp + 1 + lenb, num[i].b) - tmp;
  int ans = 0;
  t.build(1, lenb, 1);
  int minn = num[1].a; int l = 1;

  //	For(i,1,n){
  //		cout<<num[i].a<<' '<<num[i].b<<' '<<num[i].c<<endl;
  //	}
  For(i, 2, n) {
    if (num[i].a < minn) {
      minn = num[i].a;
      For(j, l, i - 1)
      t.updata(num[j].b, 1, num[j].c);
      l = i;
    }

    if (t.getmax(num[i].b + 1, lenb, 1) > num[i].c) ans++;
  }
  Pri(ans);
}

// 9
// 7
// 7
// 7
// 5
// 2
// 1
// 1
// 1
