#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
typedef pair<int, int> pdi;
typedef pair<ll, int> pli;

int const maxn = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
inline int lc(int x)  {return x << 1;}
inline int rc(int x)  {return x << 1 | 1;}

char name[maxn];
struct strHash {
    const char *s;
    int len, base, mod;
    int Hash[maxn], p[maxn];
    void modify(const size_t &len, const char *s, int base, int mod) {
        this->base = base;
        this->len = len;
        this->s = s;
        this->mod = mod;
        hash_value();
    }
    void hash_value() {
        Hash[0] = 0;
        p[0] = 1;
        for (int i = 1; i <= len; i++) {
            Hash[i] = (1LL * Hash[i - 1] * base + s[i]) % mod;
            p[i] = 1LL * p[i - 1] * base % mod;
        }
    }
    int get_hash(int l, int r) {
        return (Hash[r] - 1LL * Hash[l - 1] * p[r - l + 1] % mod + mod) % mod;
    }
    int get_hash() { return get_hash(1, this->len); }
    int pos_change(int pos, char x) {
        int ans = 0;
        ans = (ans + 1LL * x * p[len - pos] % mod) % mod;
        if (pos < len) {
            ans = (ans + get_hash(pos + 1, len)) % mod;
        }
        if (pos > 1) {
            ans = (ans + 1LL * get_hash(1, pos - 1) * p[len - pos + 1] % mod) % mod;
        }
        return ans;
    }
};

struct DoubleHash {
    strHash Hash[2];
    const int base[6] = {131, 56369, 99991, 999983, 16341163, 19260817};
    const int mod[7] = {19260817, 999998639,  999998641, 100000007,
                        1000000007, 1000000009, 1000000103};
    void modify(int n, const char *s) {
        for (int i = 0; i < 2; i++) {
            Hash[i].modify(n, s, base[i], mod[i]);
        }
    }
    int get_hash() {
        return ((Hash[0].get_hash()) + Hash[1].get_hash()) ^ 0x333FFFFF;
    }
};
DoubleHash table;

int main(void) {
    FAST_IO;
    
    freopen("../user.txt", "r", stdin);
    int id;
    unordered_map<int, int> hashmp;
    vector<pair<string, int>> psd;

    vector<string> rnd_psd;
    while (cin >> id >> name + 1) {
        // cout << 1 << endl;
        // cout << name + 1 << endl;
        int len = strlen(name + 1);
        table.modify(len, name);
        auto hashval = table.get_hash();
        if (!hashmp.count(hashval) && rnd_psd.size() < 2000) {      // 前2000个存在的
            rnd_psd.emplace_back(string(name + 1));
            // cout << name + 1 << endl;
        }
        hashmp[hashval]++;
    }
    // for ()
    char chararset[70];
    for (int i = 0; i <= 9; i++) {
        chararset[i] = 48 + i;
    }
    for (int i = 10, j = 0; i <= 35; i++, j++) {
        chararset[i] = j + 65;
    }
    for (int i = 36, j = 0; i <= 61; i++, j++) {
        chararset[i] = j + 97;
    }
    for (int i = 0; i < 62; i++) {
        cout << chararset[i];
    }
    cout << endl;

    srand((unsigned)time(nullptr));
    for (int o = 1; o <= 2000; o++) {      // 2000个不存在的
        int len = (rand() % 14) + 6;
        string s = "";
        do {
            s = "";
            for (int i = 0; i < len; i++) {
                int x = rand() % 62;
                s += chararset[x];
            }
            table.modify(s.length(), s.c_str());
        } while (s == "" || hashmp.count(table.get_hash()));
        rnd_psd.emplace_back(s);
    }

//    random_shuffle(rnd_psd.begin(), rnd_psd.end());     // 随机打乱
    ofstream fout("rand.txt", ios::out);
    for (auto & x : rnd_psd) {
        fout << x << endl;
    }
    fout.close();

    return 0;
}
