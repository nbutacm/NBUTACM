#include <bits/stdc++.h>
using namespace std;       //     ____   _   _  __   __
#define ll long long       //    / ___| | |_| |   / /
const ll INF = 0x3f3f3f3f; //   | |     |  _  |   V /
const ll N   = 1e5 + 5;    //   | |___  | | | |   | |
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
      tree[x].sum = tree[x].max = tree[x].min = 0;

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
} tree1, tree2;

int n;
struct node {
  ll val, pos;
}  a[N];
ll l[N], r[N], ans;

int cmp(node a, node b) {
  if (a.val == b.val) return a.pos < b.pos;
  else return a.val < b.val;
}

int main() {
  for (int _ = read(); _; _--) {
    n = read();

    for (int i = 1; i <= n; i++) {
      a[i].val = read();
      a[i].pos = i;
      l[i]     = r[i] = ans = 0;
    }
    tree1.build(1, 1, n);
    tree2.build(1, 1, n);
    sort(a + 1, a + 1 + n, cmp);
    int num = 0;

    for (int i = 1; i <= n; i++) {
      num         = tree1.querySUM(1, 1, a[i].pos);
      l[a[i].pos] = num;
      tree1.update(1, a[i].pos, a[i].pos, 1);
    }

    for (int i = n; i >= 1; i--) {
      num         = tree2.querySUM(1, a[i].pos, n);
      r[a[i].pos] = num;
      tree2.update(1, a[i].pos, a[i].pos, 1);
    }

    // for (int i = 1; i <= n; i++) {
    //   cout << l[i] << " ";
    // } cout << endl;
    //
    // for (int i = 1; i <= n; i++) {
    //   cout << r[i] << " ";
    // } cout << endl;

    for (int i = 2; i <= n - 1; i++) {
      ans += l[i] * r[i];
      ans += (i - 1 - l[i]) * (n - i - r[i]);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
