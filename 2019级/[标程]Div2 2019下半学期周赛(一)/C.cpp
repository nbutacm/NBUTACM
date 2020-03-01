#include <bits/stdc++.h> 
using namespace std;

int main(void) {
    int p, q;
    while(cin >> p >> q)
        cout << p + q - __gcd(p, q) << endl;
    
    return 0;
}
