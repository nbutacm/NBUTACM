// #include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll N = 1e6 + 5;
const ll MOD = 1e9 + 7;
ll  MAX = 0, MIN = INF;
int res[105];
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
    int l, r, col;
    ll  sum, lz, max, min;
    void update(ll v) {
      sum = v;
      lz  = v;
      max = v;
      min = v;

      //			col=v;
    }
  } tree[N * 4];

  void modify(ll *arr) {
    a = arr;
  }

  void pushup(int x) {
    tree[x].sum = tree[2 * x].sum | tree[2 * x + 1].sum;

    //		tree[x].max=max(tree[2*x].max,tree[2*x+1].max);
    //		tree[x].min=min(tree[2*x].min,tree[2*x+1].min);
  }

  void pushdown(int x) {
    //			tree[2*x].col=tree[2*x+1].col=tree[x].col;
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

      // tree[x].col=1;
      return;
    }
    int mid = (l + r) / 2;
    build(2 * x,     l,       mid);
    build(2 * x + 1, mid + 1, r);
    pushup(x);
  }

  void update(int x, int l, int r, ll c) {
    int L   = tree[x].l;
    int R   = tree[x].r;
    int mid = (L + R) / 2;

    if ((l <= L) && (r >= R)) {
      tree[x].update(c);
      return;
    }

    // if(tree[x].col!=-1)
    pushdown(x);

    if (l <= mid) update(2 * x, l, r, c);

    if (r > mid) update(2 * x + 1, l, r, c);
    pushup(x);
  }

  ll querySUM(int x, int l, int r) {
    int L   = tree[x].l;
    int R   = tree[x].r;
    int mid = (L + R) / 2;
    ll  res = 0;

    if ((l <= L) && (r >= R)) {
      return tree[x].sum;
    }

    pushdown(x);

    if (l <= mid) res |= querySUM(2 * x, l, r);

    if (r > mid) res |= querySUM(2 * x + 1, l, r);

    // pushup(x);
    return res;
  }
} tree;

ll   n, m, a[N], l, r, v, CASE, L, O;
char s[10];
int  T;

int main() {
  scanf("%lld%d%lld", &L, &T, &O);

  for (int i = 1; i <= L; i++) a[i] = 1;
  tree.modify(a);
  tree.build(1, 1, L);

  for (int i = 1; i <= O; i++) {
    scanf("%s", s);

    if (s[0] == 'C') {
      l = read(), r = read(), v = read();

      if (l > r) swap(l, r);
      tree.update(1, l, r, 1 << (v - 1));
    } else if (s[0] == 'P') {
      l = read(), r = read();

      if (l > r) swap(l, r);

      // memset(res,0,sizeof(res));
      ll ans = tree.querySUM(1, l, r);
      ll cnt = 0;

      for (int i = 0; i <= T - 1; i++) {
        if ((ans >> i) & 1) cnt++;
      }
      printf("%d\n", cnt);
    }
  }

  // printf("\n");
  return 0;
}
