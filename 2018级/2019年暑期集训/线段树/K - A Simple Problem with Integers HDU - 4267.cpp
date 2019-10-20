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

int idx[100];
struct segt {
  struct Tree {
    int l, r;
    int sum, lz[56];
    void update(int v, int k) {
      lz[k] += v;
    }
  } tree[N * 4];

  void pushup(int x) {}

  void pushdown(int x) {
    for (int i = 0; i <= 55; i++) {
      if (tree[x].lz[i] != 0) {
        tree[2 * x].update(tree[x].lz[i], i);
        tree[2 * x + 1].update(tree[x].lz[i], i);
        tree[x].lz[i] = 0;
      }
    }
  }

  void build(int x, int l, int r) {
    tree[x].l   = l;
    tree[x].r   = r;
    tree[x].sum = 0;

    for (int i = 0; i <= 55; i++) tree[x].lz[i] = 0;

    if (l == r) {
      // tree[x].sum = tree[x].max = tree[x].min = a[l];

      return;
    }
    int mid = (l + r) / 2;
    build(2 * x,     l,       mid);
    build(2 * x + 1, mid + 1, r);

    // pushup(x);
  }

  void update(int x, int l, int r, int c, int k) {
    int L = tree[x].l, R = tree[x].r;
    int mid = (L + R) / 2;

    if ((l <= L) && (r >= R)) {
      tree[x].update(c, k);
      return;
    }

    pushdown(x);

    if (l <= mid) update(2 * x, l, r, c, k);

    if (r > mid) update(2 * x + 1, l, r, c, k);

    // pushup(x);
  }

  int querySUM(int x, int l, int r) {
    int L = tree[x].l, R = tree[x].r;
    int mid = (L + R) / 2;
    int res = 0;

    if ((l <= L) && (r >= R)) { // 要更新区间包括了该区间
      int ans = 0;

      for (int i = 1; i <= 10; i++) {
        ans += tree[x].lz[idx[i - 1] + l % i];
      }
      return ans;
    }

    pushdown(x);

    if (l <= mid) res += querySUM(2 * x, l, r);

    if (r > mid) res += querySUM(2 * x + 1, l, r);

    // pushup(x);
    return res;
  }
} tree;

int n, q, a[N], l, r, k, v, ope;
int ans;

int main() {
  for (int i = 1; i <= 10; i++) idx[i] += idx[i - 1] + i;

  while (cin >> n) {
    for (int i = 1; i <= n; i++) a[i] = read();
    tree.build(1, 1, n);
    q = read();

    while (q--) {
      ope = read();

      if (ope == 2) {
        l = read();
        int ans = 0;
        ans += tree.querySUM(1, l, l);
        printf("%d\n", ans + a[l]);
      }
      else {
        l = read(), r = read(), k = read(), v = read();
        tree.update(1, l, r, v, idx[k - 1] + l % k);
      }
    }
  }

  return 0;
}
