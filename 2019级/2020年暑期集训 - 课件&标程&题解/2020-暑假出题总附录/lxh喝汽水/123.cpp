#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
    
char a1[1100000];
int f[1100000];
int num[2100000];
int main() {
    
    while (cin >> (a1 + 1)) {
        memset(f, 0, sizeof(f));
        int n = strlen(a1 + 1);
        if(a1[1]=='G')f[1]=1;
        else f[1]=-1;
        for (int i = 2; i <= n; ++i) {
            if (a1[i] == 'G')
                f[i] =1+ f[i - 1];
            else if (a1[i] == 'R')
                f[i] =-1+ f[i - 1];
        }
          
        int ans = 0;
        for (int i = 1; i < 2 * n + 10; i++)
            num[i] = 0x3f3f3f;
        num[n] = 0;
        for (int i = 1; i <= n; i++) {
            num[f[i] + n] = min(i, num[f[i] + n]);
           	cout << num[f[i] + n] << "   "; 
            ans = max(ans, i - num[f[i] + n]);
        }
        cout << endl;
        cout << ans << endl;
    }
    return 0; 
}
