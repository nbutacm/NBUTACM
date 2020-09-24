#include <bits/stdc++.h>

using namespace std;

int main(void) {
    freopen("random_id.txt", "w", stdout);
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    default_random_engine e(seed);
    vector<int> v;
    int base = 1230000;
    int limit = base << 1;
    uniform_int_distribution<int> u(1, base);
    uniform_int_distribution<int> g(base + 1, limit);
    for (int i = 0; i < 2000; i++) {
        v.emplace_back(u(e));
    }
    for (int i = 0; i < 2000; i++) {
        v.emplace_back(g(e));
    }
    random_shuffle(v.begin(), v.end());
    for (auto & x : v) {
        cout << x << endl;
    }
    return 0;
}
