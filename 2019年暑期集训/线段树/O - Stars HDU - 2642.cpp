#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false), std::cin.tie(0), \
  std::cout.tie(0)
#define pause system("pause")
typedef long long    ll;
typedef unsigned int UINT;
int const maxn = 1000 + 10;
using namespace std;
int vis[maxn][maxn];
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
    for (int i = x; i < maxn; i += lowbit(i)) {
      for (int j = y; j < maxn; j += lowbit(j)) {
        s[i][j] += v;
      }
    }
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
  int m;
  cin >> m;

  while (m--) {
    char opt[5];
    int  x1, x2, y1, y2;
    cin >> opt;

    if (opt[0] == 'B') {
      cin >> x1 >> y1;
      ++x1, ++y1;

      if (!vis[x1][y1]) {
        vis[x1][y1] = 1;
        tree.update(x1, y1, 1);
      }
    } else if (opt[0] == 'D') {
      cin >> x1 >> y1;
      ++x1, ++y1;

      if (vis[x1][y1]) {
        vis[x1][y1] = 0;
        tree.update(x1, y1, -1);
      }
    } else {
      cin >> x1 >> x2 >> y1 >> y2;
      x1++, x2++, y1++, y2++;

      if (x1 > x2) swap(x1, x2);

      if (y1 > y2) swap(y1, y2);
      int ans = tree.query(x2, y2) + tree.query(x1 - 1, y1 - 1)
                - tree.query(x1 - 1, y2) - tree.query(x2, y1 - 1);
      cout << ans << endl;
    }
  }

  // pause;
  return 0;
}
