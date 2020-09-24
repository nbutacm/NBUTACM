#include <bits/stdc++.h>
#include "../HashMap/HashMap.h"

using namespace std;
using namespace CornMing;

struct DHash {
    unsigned h1(const string &str) const {
        int len = str.length();
        int base = 131, mod = 19260817;
        unsigned Hash = 0;
        for (int i = 1; i <= len; i++) {
            Hash = (1LL * Hash * base + str[i - 1]) % mod;
        }
        return Hash;
    }

    unsigned h2(const string &str) const {
        int len = str.length();
        int base = 56369, mod = 999998639;
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
    HashMap<string, int, DHash> hashmap(40000);
    vector<string> v;
    

    while (~scanf("%s", psd)) {
        int val = 0;
        hashmap.find(string(psd), val);
        hashmap.insert(string(psd), val + 1);
    }
    ofstream fout("password_Hash_Search.txt", std::ios::out);
    ifstream fin("randmoize.txt");
    
    int cnt = 0;
    clock_t startTime = clock();
    while (fin >> psd) {
    	v.push_back(string(psd));
    	int val = 0;
		if (hashmap.find(psd, val)) {
			cnt++;
			fout << psd << "\t" << val << endl;
		}
	}
	clock_t endTime = clock();
	fin.close();
    fout.close();

    ofstream resout("result_time/password_Hash_Search.txt", std::ios::out);
    double result = (double)(endTime - startTime);
	resout << "Success of : " << cnt << endl;
    resout << "The run time is: " << fixed << setprecision(6) 
            <<  result / CLOCKS_PER_SEC << "s" << endl;
    resout.close();

    return 0;
}
