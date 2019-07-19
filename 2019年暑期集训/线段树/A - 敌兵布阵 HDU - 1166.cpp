#include <bits/stdc++.h>
using namespace std;       //     ____   _   _  __   __
#define ll long long       //    / ___| | |_| |   / /
const ll INF = 0x3f3f3f3f; //   | |     |  _  |   V /
const ll N   = 5e4 + 5;    //   | |___  | | | |   | |
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
  struct Tree {
    int l, r;
    ll  sum, lz, max, min;
    void update(ll v) {
      sum += v * (r - l + 1);
      lz  += v;
      max += v;
      min += v;
    }
  } tree[N * 4];

  void modify(ll *arr) {
    a = arr;
  }

  void pushup(int x) {
    tree[x].sum = tree[2 * x].sum + tree[2 * x + 1].sum;
    tree[x].max = max(tree[2 * x].max, tree[2 * x + 1].max);
    tree[x].min = min(tree[2 * x].min, tree[2 * x + 1].min);
  }

  void pushdown(int x) {
    if (tree[x].lz != 0) {
      tree[2 * x].update(tree[x].lz);
      tree[2 * x + 1].update(tree[x].lz);
      tree[x].lz = 0;
    }
  }

  void build(int x, int l, int r) {
    tree[x].l   = l;
    tree[x].r   = r;
    tree[x].sum = tree[x].max = tree[x].min = tree[x].lz = 0;

    if (l == r) {
      tree[x].sum = tree[x].max = tree[x].min = a[l];

      return;
    }
    int mid = (l + r) / 2;
    build(2 * x,     l,       mid);
    build(2 * x + 1, mid + 1, r);
    pushup(x);
  }

  void update(int x, int l, int r, ll c) {
    int L = tree[x].l, R = tree[x].r;
    int mid = (L + R) / 2;

    if ((l <= L) && (r >= R)) {
      tree[x].update(c);
      return;
    }

    pushdown(x);

    if (l <= mid) update(2 * x, l, r, c);

    if (r > mid) update(2 * x + 1, l, r, c);
    pushup(x);
  }

  ll querySUM(int x, int l, int r) {
    int L = tree[x].l, R = tree[x].r;
    int mid = (L + R) / 2;
    ll  res = 0;

    if ((l <= L) && (r >= R)) { // 要更新区间包括了该区间
      return tree[x].sum;
    }

    pushdown(x);

    if (l <= mid) res += querySUM(2 * x, l, r);

    if (r > mid) res += querySUM(2 * x + 1, l, r);
    return res;
  }
} tree;

ll   n, a[N], l, r, v, CASE;
char s[10];
ll   ans;

int main() {
  CASE = 1;

  for (int _ = read(); _; _--) {
    n = read();

    for (int i = 1; i <= n; i++) a[i] = read();
    tree.modify(a);
    tree.build(1, 1, n);
    printf("Case %d:\n", CASE++);

    while (~scanf("%s", s)) {
      if (s[0] == 'E') break;
      else if (s[0] == 'A') {
        l = read(), v = read();
        tree.update(1, l, l, v);
      }
      else if (s[0] == 'S') {
        l = read(), v = read();
        tree.update(1, l, l, -v);
      }
      else {
        l   = read(), r = read();
        ans = tree.querySUM(1, l, r);
        printf("%lld\n", ans);
      }
    }
  }
  return 0;
}
