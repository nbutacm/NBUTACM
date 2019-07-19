#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false), std::cin.tie(0), \
  std::cout.tie(0)
#define pause system("pause")
typedef long long          ll;
typedef unsigned int       UINT;
typedef unsigned long long ull;
using namespace std;
int const maxn = 5000 + 10;
ll n;
ll a[maxn];

struct BIT {
private:

  ll s[maxn];
  inline int lowbit(int x) {
    return x & -x;
  }

public:

  BIT() {
    memset(s, 0, sizeof(s));
  }

  void update(int x, int v) {
    for (int i = x; i <= n; i += lowbit(i)) {
      s[i] += v;
    }
  }

  ll query(int x) {
    ll sum = 0;

    for (int i = x; i > 0; i -= lowbit(i)) {
      sum += s[i];
    }
    return sum;
  }
};

int main(void) {
  // FAST_IO;
  while (scanf("%lld", &n) != EOF) {
    BIT tree;

    for (int i = 1; i <= n; i++) {
      scanf("%lld", a + i);
      a[i]++;
    }
    ll ans = 0;

    for (int i = 1; i <= n; i++) {
      tree.update(a[i], 1);
      ans += i - tree.query(a[i]);
    }
    ll m = ans;

    for (int i = 1; i <= n; i++) {
      ans = ans - a[i] + n - a[i] + 1;
      m   = min(ans, m);
    }

    // cout << m << endl;
    printf("%lld\n", m);
  }

  // pause;
  return 0;
}
