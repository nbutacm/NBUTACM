// #include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#define FAST_IO std::ios::sync_with_stdio(false), std::cin.tie(0), \
  std::cout.tie(0)
#define pause system("pause")
typedef long long          ll;
typedef unsigned int       UINT;
typedef unsigned long long ull;
using namespace std;
int const maxn = 1000 + 10;
int vis[maxn][maxn];
int n;

struct BIT {
private:

  int s[maxn][maxn];
  inline int lowbit(int x) {
    return x & -x;
  }

public:

  BIT() {
    memset(s, 0, sizeof(s));
  }

  void update(int x, int y, int v) {
    for (int i = x; i <= n; i += lowbit(i)) {
      for (int j = y; j <= n; j += lowbit(j)) {
        s[i][j] += v;
      }
    }
  }

  void init() {
    memset(s, 0, sizeof(s));
  }

  int query(int x, int y) {
    int sum = 0;

    for (int i = x; i > 0; i -= lowbit(i)) {
      for (int j = y; j > 0; j -= lowbit(j)) {
        sum += s[i][j];
      }
    }
    return sum;
  }
} tree;


int main(void) {
  FAST_IO;
  int t;
  cin >> t;

  while (t--) {
    memset(vis, 0, sizeof(vis));
    tree.init();
    int m;
    cin >> n >> m;
    char opt[5];
    int  x1, x2, y1, y2;

    for (int i = 0; i < m; i++) {
      cin >> opt;

      if (opt[0] == 'C') {
        cin >> x1 >> y1 >> x2 >> y2;
        tree.update(x1,     y1,     1);
        tree.update(x2 + 1, y2 + 1, 1);
        tree.update(x1,     y2 + 1, -1);
        tree.update(x2 + 1, y1,     -1);
      } else {
        cin >> x1 >> y1;
        cout << (tree.query(x1, y1)) % 2 << endl;
      }
    }
    cout << endl;
  }

  // pause;
  return 0;
}
