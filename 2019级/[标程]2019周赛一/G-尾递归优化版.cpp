#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int const MOD = 1e9 + 7;
 
ll sovle(int x, int f1, int f2) {
    if (x == 0) return 0;
    if (x == 1)
        return 2;
    if (x <= 2) 
        return f2;
    return sovle(x - 1, f2, (f1 + f2) % MOD);
}
 
int main(void) {
	
    int n;
    cin >> n;
    cout << sovle(n, 2, 3) << endl;
     
    return 0;
}
