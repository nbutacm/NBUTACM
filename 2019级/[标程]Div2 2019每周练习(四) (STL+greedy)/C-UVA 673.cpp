#include <iostream>
#include <stack>
#include <string>
#include <cstdio>
using namespace std;

int main() {
    int t;
    cin >> t;
    getchar();
    while(t--) {
        string s;
        getline(cin, s);
        stack<char> sk;
        int flag=0;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='(' || s[i]=='[') sk.push(s[i]);
            else if(!sk.empty() && s[i]==')' && sk.top()=='(') sk.pop();
            else if(!sk.empty() && s[i]==']' && sk.top()=='[') sk.pop();
            else flag=1;
        }
        if(flag == 0  && sk.size() == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}

