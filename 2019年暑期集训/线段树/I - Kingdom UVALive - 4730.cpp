#include <bits/stdc++.h>
using namespace std;       //     ____   _   _  __   __
#define ll long long       //    / ___| | |_| |   / /
const ll INF = 0x3f3f3f3f; //   | |     |  _  |   V /
const ll N   = 1e6 + 5;    //   | |___  | | | |   | |
const ll MOD = 1e9 + 7;    //    ____| |_| |_|   |_|
ll read() {
  ll   x = 0, f = 1;
  char ch = getchar();

  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1; ch = getchar();
  }

  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0'; ch = getchar();
  }
  return x * f;
}

struct segt {
  ll *a;
  ll  SUM1, SUM2;
  struct Tree {
    int l, r;
    ll  sum1, lz1, sum2, lz2;
    void update(ll v1, ll v2) {
      sum1 += v1 * (r - l + 1);
      sum2 += v2 * (r - l + 1);
      lz1  += v1;
      lz2  += v2;
    }
  } tree[N * 4];

  void modify(ll *arr) {
    a = arr;
  }

  void pushup(int x) {
    tree[x].sum1 = tree[2 * x].sum1 + tree[2 * x + 1].sum1;
    tree[x].sum2 = tree[2 * x].sum2 + tree[2 * x + 1].sum2;
  }

  void pushdown(int x) {
    if ((tree[x].lz1 != 0) || (tree[x].lz2 != 0)) {
      tree[2 * x].update(tree[x].lz1, tree[x].lz2);
      tree[2 * x + 1].update(tree[x].lz1, tree[x].lz2);
      tree[x].lz1 = 0;
      tree[x].lz2 = 0;
    }
  }

  void build(int x, int l, int r) {
    tree[x].l    = l;
    tree[x].r    = r;
    tree[x].sum1 = tree[x].lz1 = 0;
    tree[x].sum2 = tree[x].lz2 = 0;

    if (l == r) {
      // tree[x].sum = tree[x].max = tree[x].min = a[l];

      return;
    }
    int mid = (l + r) / 2;
    build(2 * x,     l,       mid);
    build(2 * x + 1, mid + 1, r);
    pushup(x);
  }

  void update(int x, int l, int r, ll c1, ll c2) {
    int L = tree[x].l, R = tree[x].r;
    int mid = (L + R) / 2;

    if ((l <= L) && (r >= R)) {
      tree[x].update(c1, c2);
      return;
    }

    pushdown(x);

    if (l <= mid) update(2 * x, l, r, c1, c2);

    if (r > mid) update(2 * x + 1, l, r, c1, c2);
    pushup(x);
  }

  void query(int x, int l, int r) {
    int L = tree[x].l, R = tree[x].r;
    int mid = (L + R) / 2;
    ll  res = 0;

    if ((l <= L) && (r >= R)) { // 要更新区间包括了该区间
      SUM1 += tree[x].sum1;
      SUM2 += tree[x].sum2;
      return;
    }

    pushdown(x);

    if (l <= mid) query(2 * x, l, r);

    if (r > mid) query(2 * x + 1, l, r);
    pushup(x);
  }
} tree;

int n, m;
struct node {
  int up, down;
}    p[N];
int  fa[N], num[N];
char ope[10];

int find(int x) {
  return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void Union(int x, int y) {
  int fx = find(x), fy = find(y);

  if (fx != fy) {
    if (p[fx].up > p[fx].down) {
      tree.update(1, p[fx].down + 1, p[fx].up, -1, -num[fx]);
    }

    if (p[fy].up > p[fy].down) {
      tree.update(1, p[fy].down + 1, p[fy].up, -1, -num[fy]);
    }
    fa[fy]   = fx;
    num[fx] += num[fy];
    int up   = max(p[fx].up, p[fy].up);
    int down = min(p[fx].down, p[fy].down);
    p[fx].up   = up;
    p[fx].down = down;

    if (p[fx].up > p[fx].down) {
      tree.update(1, p[fx].down + 1, p[fx].up, 1, num[fx]);
    }
  }
}

int main() {
  for (int _ = read(); _; _--) {
    n = read();

    for (int i = 1; i <= n; i++) {
      int x = read(), y = read();
      p[i].up = p[i].down = y;
      fa[i]   = i;
      num[i]  = 1;
    }
    m = read();
    tree.build(1, 1, 1000000);

    while (m--) {
      scanf("%s", ope);

      if (ope[0] == 'r') {
        int x = read(), y = read();
        x++, y++;
        Union(x, y);
      }
      else {
        double pos;
        scanf("%lf", &pos);
        tree.SUM1 = 0;
        tree.SUM2 = 0;
        tree.query(1, (int)pos + 1, (int)pos + 1);
        printf("%lld %lld\n", tree.SUM1, tree.SUM2);
      }
    }
  }
  return 0;
}

// 设置下端点取不到

/*
   1
   5
   1 1
   1 2
   1 2
   1 3
   1 0
   99
   r 0 1
   r 2 3
   l 1.5
   l 2.5
   r 0 4
   l 0.5
   r 0 2
   l 0.5
   l 1.5
   l 2.5
   l 3.5
 */
