#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int T, a, b, c;
    scanf("%d",&T);
    while(T--) {
        cin >> a >> b >> c;
        if(a == 0) {
            cout << 1 << endl;
            continue;
        }
        if(a + b * 2 < 4) {
            cout << a + 2*b+1 << endl;
            continue;
        }
        cout << a + b*2 + 5*c + 1 << endl; 
    }
    return 0;
}