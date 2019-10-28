#include <bits/stdc++.h>
using namespace std;
int const maxn = 1e5 + 10;
char s[maxn]; 
int main(void) {
    int G = 0, L = 0, J = 0, n = 0, b = 0;
    cin >> s;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == 'G') G++;
        if (s[i] == 'L') L++;
        if (s[i] == 'J') J++;
        if (s[i] == 'n') n++;
        if (s[i] == 'b') b++;
    }   
     
    while (G > 0 || L > 0 || J > 0 || n > 0 || b > 0) {
        if (G-- > 0) cout << 'G';
        if (L-- > 0) cout << 'L';
        if (J-- > 0) cout << 'J';
        if (n-- > 0) cout << 'n';
        if (b-- > 0) cout << 'b'; 
    }
//    cout << endl;
     
    return 0;
}
