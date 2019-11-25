#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    set<string> st;
    string s;
    
    while (cin >> s) {
        for (int i = 0; i < s.length(); i++) {
            if (!isalpha(s[i])) {
                s[i] = ' ';
            }
            else s[i] = tolower(s[i]);
        }
        stringstream ss(s);
        while (ss >> s) {
            st.insert(s);
        }
    }
    
    for (set<string>::iterator it = st.begin(); it != st.end(); it++)
        cout << *it << endl;

    return 0;
}
