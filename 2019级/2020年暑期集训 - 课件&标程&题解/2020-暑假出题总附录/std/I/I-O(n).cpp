#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e7 + 10;
long long f[maxn], flag[maxn], prime[maxn];
int is_prime[maxn];

void init() {
    f[1] = 1;
    for(int i = 2; i < maxn; i++)
        is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    int num = 0;
    for(int i = 2; i < maxn; i++) {
        if(is_prime[i]) {
            f[i] = 2;
            flag[i] = 1;
            prime[num++] = i;
        }
        for(int j = 0; j < num; j++) {
            if(i * prime[j] > maxn)
                break;
            is_prime[i * prime[j]] = false;
            if(i % prime[j] == 0) {
                flag[i * prime[j]] = flag[i] + 1;
                f[i * prime[j]] = f[i] / (flag[i] + 1) * (flag[i * prime[j]] + 1);
                break;
            }
            flag[i * prime[j]] = 1;
            f[i * prime[j]] = f[i] * 2;
        }
    }
}
 
int main(void) {
    init();
    long long  ans = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        ans += i * f[i];
    }
    cout << ans << endl;
     
    return 0;
}
