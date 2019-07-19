#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
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
  ll  MAX, MIN;
  struct Tree {
    int l, r;
    ll  sum, lz, max, min;
    void update() {
      sum = (ll)sqrt(sum);
      lz  = 0;
      max = 0;
      min = 0;
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
    // if (tree[x].lz != 0) {
    //   tree[2 * x].update(tree[x].lz);
    //   tree[2 * x + 1].update(tree[x].lz);
    //   tree[x].lz = 0;
    // }
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

  void update(int x, int l, int r) {
    int L = tree[x].l, R = tree[x].r;
    int mid = (L + R) / 2;

    if (tree[x].sum == (R - L + 1)) return;

    if ((l <= L) && (r >= R) && (L == R)) {
      tree[x].update();
      return;
    }

    pushdown(x);

    if (l <= mid) update(2 * x, l, r);

    if (r > mid) update(2 * x + 1, l, r);
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

    // pushup(x);
    return res;
  }
} tree;

int n, m, ope, l, r, v;
ll  a[N], ans;

int main() {
  int CASE = 1;

  while (cin >> n) {
    for (int i = 1; i <= n; i++) a[i] = read();
    tree.modify(a);
    tree.build(1, 1, n);
    m = read();
    printf("Case #%d:\n", CASE++);

    while (m--) {
      ope = read();
      l   = read();
      r   = read();

      if (l > r) swap(l, r);

      if (ope == 0) {
        tree.update(1, l, r);
      }
      else {
        printf("%lld\n", tree.querySUM(1, l, r));
      }
    }
    printf("\n");
  }
  return 0;
}
