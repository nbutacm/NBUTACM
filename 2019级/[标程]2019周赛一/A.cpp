#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << max(0, a - 2 * b) << endl;
    }
    return 0;
}
