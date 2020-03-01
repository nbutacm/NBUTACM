#include <iostream>
#include <algorithm>
using namespace std;
int const maxn = 20;
int map[maxn], s[maxn];
int ans;
bool check(int a) {
    for (int i = 1; i < a; i++) {
        if ((abs(a - i) == abs(map[a] - map[i])) || map[i] == map[a])
            return false;
    }
    return true;
}
void dfs(int x, int n) {
    if (x == n + 1) {
        ans++;
        return;
    }
    for (int i = 1; i <= n; i++) {
        map[x] = i;
        if (check(x)) {
            dfs(x + 1, n);
        }
    }
}

int main(void) {
    for (int i = 1; i <= 10; i++) {
        ans = 0;
        dfs(1, i);
        s[i] = ans;
    }
    int n;
    while (cin >> n && n) {
        cout << s[n] << endl;
    }
    return 0;
}
