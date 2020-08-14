#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <iostream>
#include <iomanip>
#include <bitset>
#include <string>
#include <set>
#include <stack>
#include <sstream>
#include <list>
//#include <array>
#include <vector>
#include <queue>
#include <map>
#include <memory>
#include <iterator>
#include <climits>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
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
int main(void) {
    FAST_IO;
     
    // string s;
    while (~scanf("%s", s + 1)) {
        int len = strlen(s + 1);
        map<int, vector<int>> mp;
        mp[0].push_back(0);
        for (int i = 1; i <= len; i++){
            pre[i] = pre[i - 1] + ((s[i] == 'R' )? 1 : -1);
            mp[pre[i]].push_back(i);
        }
        int ans = 1;
        for (auto &x : mp) {
            ans = max(ans, x.second.back() - x.second.front());
        }
        // cout << ans << endl;
        printf("%lld\n", ans);
    }
 
    return 0;
}
