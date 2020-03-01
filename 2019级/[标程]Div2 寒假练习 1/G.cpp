#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int const maxn = 1e5 + 10;
const double eps = 1e-5;

double a[maxn], b[maxn], sum[maxn];
int n, L;

bool check(double mid) {
    for (int i = 1; i <= n; i++) {
        b[i] = a[i] - mid;
    }
    for (int i = 1; i <= n; i++) {
        sum[i] = (sum[i - 1] + b[i]);
    }
    double ans = -1e10;
    double min_val = 1e10;
    for (int i = L; i <= n; i++) {
        min_val = min(min_val, sum[i - L]);
        ans = max(ans, sum[i] - min_val);
    }
    return ans >= 0;
}
int main(void) {
    scanf("%d %d", &n, &L);
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &a[i]);
    }
    
    double l = -1e6, r = 1e6;
    while (r - l > eps) {
        double mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }

    printf("%d\n", (int)(r * 1000));
    
    return 0;
}
