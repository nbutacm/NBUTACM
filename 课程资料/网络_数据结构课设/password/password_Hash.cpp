#include <bits/stdc++.h>
#include "../HashMap/HashMap.h"

using namespace std;
using namespace CornMing;

struct DHash {
    unsigned h1(const string &str) const {
        const int len = str.length();
        const int base = 131, mod = 19260817;
        unsigned Hash = 0;
        for (int i = 1; i <= len; i++) {
            Hash = (1LL * Hash * base + str[i - 1]) % mod;
        }
        return Hash;
    }

    unsigned h2(const string &str) const {
        const int len = str.length();
        const int base = 56369, mod = 999998639;
        unsigned Hash = 0;
        for (int i = 1; i <= len; i++) {
            Hash = (1LL * Hash * base + str[i - 1]) % mod;
        }
        return Hash;
    }

    unsigned operator()(const string &s) const {
        return (h1(s) << 16) ^ (h2(s) >> 16);
    }
};


int main(void) {
    freopen("../user.txt", "r", stdin);
    char psd[50];
    int id;
    HashMap<string, int, DHash> hashmap(56369);
    vector<string> v;
    clock_t startTime = clock();

    while (~scanf("%d %s", &id, psd)) {
        int val = 0;
        if (!hashmap.find(string(psd), val)) {
            v.emplace_back(string(psd));
        }
        hashmap.insert(psd, val + 1);
    }
    ofstream fout("password.txt", std::ios::out);
    for (auto &x : v) {
        int val = 0;
        hashmap.find(x, val);
        fout << x << "\t" << val << endl;
    }
    clock_t endTime = clock();
    fout.close();

    ofstream resout("result_time/password_Hash_result.txt", std::ios::out);
    double result = (double)(endTime - startTime);

    resout << "The run time for HashMap is: " << fixed << setprecision(3) 
            <<  result / CLOCKS_PER_SEC << "s" << endl;
    resout.close();

    return 0;
}
