#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;

int main() {
    map<string , int>M;
    int n = 0;
    string str;
    while (cin >> n && n != 0) {
        M.clear();
        while (n--) {
            cin >> str;
            M[str]++;
        }
        int MAX = 0;
        string ans; 
        for (map<string ,int>::iterator itor = M.begin(); itor != M.end(); ++itor){
            if (itor->second > MAX) {
                MAX = itor->second;
                ans = itor->first;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
