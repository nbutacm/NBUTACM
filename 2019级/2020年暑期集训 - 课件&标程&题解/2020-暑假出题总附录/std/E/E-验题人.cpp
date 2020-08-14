#pragma GCC oplmize(2)
#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
typedef pair<int, int> pdi;
typedef pair<ll, int> pli;
 
int const maxn = 1000000 + 10;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
inline int lc(int x)  {return x << 1;}
inline int rc(int x)  {return x << 1 | 1;}
 
int pre[maxn];
char s[maxn];
int num[maxn << 1][2];
int main(void) {
    // FAST_IO;
 
    while (~scanf("%s", s + 1)) {
        // unordered_map
        int len = strlen(s + 1);
        for (int i = 0; i <= len; i++) {
            num[i][0] = num[i][1] = 0;
            num[i + len][0] = num[i + len][1] = 0;
        }
        for (int i = 1; i <= len; i++){
            pre[i] = pre[i - 1] + ((s[i] == 'R' )? 1 : -1);
            if (pre[i] == 0) {
                num[pre[i]][1] = i;
            } else if (pre[i] < 0) {
                int x = -pre[i] + len;
                if (num[x][0] == 0) {
                    num[x][0] = i;
                } else {
                    num[x][1] = i;
                }
            } else {
                int x = pre[i];
                if (num[x][0] == 0) {
                    num[x][0] = i;
                } else {
                    num[x][1] = i;
                }
            }
        }
        int ans = 1;
        for (int i = 0; i <= len; i++) {
            ans = max(ans, num[i][1] - num[i][0]);
            ans = max(ans, num[i + len][1] - num[i + len][0]);
        }
        printf("%d\n", ans);
    }
 
     
    return 0;
}
