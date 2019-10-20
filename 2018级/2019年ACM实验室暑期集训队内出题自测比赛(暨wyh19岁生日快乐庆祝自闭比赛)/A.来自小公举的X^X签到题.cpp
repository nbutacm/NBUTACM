#include <iostream>
#include <algorithm>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
 
int main(void){
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        ll l = 1, r = 2000000000;
        while (l < r)
        {
            ll mid =(l + r) / 2;
            if ((ll)(mid * log10(mid)) + 1LL >= n) r = mid;
            else l = mid + 1;
        }
        printf("%lld\n", l);
    }
     
    return 0;
}