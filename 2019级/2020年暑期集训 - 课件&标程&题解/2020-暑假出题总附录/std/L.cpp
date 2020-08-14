#include <iostream>
//#include <bits/stdc++.h> 
#include <algorithm>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
 
int main(void){
    FAST_IO;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll l = 1, r = 2000000000;
        while (l < r)
        {
            ll mid =(l + r) >> 1;
            if ((ll)(mid * log10(mid)) + 1LL >= n) r = mid;
            else l = mid + 1;
        }
        cout << l << endl;
    }
     
    return 0;
}
