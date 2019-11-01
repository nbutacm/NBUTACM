#include<iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <set>
#include <cctype>
#include <queue>
#define ll long long
#define inf 0xffffff
using namespace std;
map <char,char> mp;
void solve()
{
     mp['Q'] = '"';         mp['W'] = '<';      mp['E'] = '>';
     mp['R'] = 'P';         mp['T'] = 'Y';      mp['Y'] = 'F';
     mp['U'] = 'G';         mp['I'] = 'C';      mp['O'] = 'R';
     mp['P'] = 'L';         mp['{'] = '?';      mp['}'] = '+';
     mp['|'] = '|';         mp['A'] = 'A';      mp['S'] = 'O';
     mp['D'] = 'E';         mp['F'] = 'U';      mp['G'] = 'I';
     mp['H'] = 'D';         mp['J'] = 'H';      mp['K'] = 'T';
     mp['L'] = 'N';         mp[':'] = 'S';      mp['"'] = '_';
     mp['Z'] = ':';         mp['X'] = 'Q';      mp['C'] = 'J';
     mp['V'] = 'K';         mp['B'] = 'X';      mp['N'] = 'B';
     mp['M'] = 'M';         mp['<'] = 'W';      mp['>'] = 'V';
     mp['?'] = 'Z';         

     mp['q'] = '\'';        mp['w'] = ',';      mp['e'] = '.';
     mp['r'] = 'p';         mp['t'] = 'y';      mp['y'] = 'f';
     mp['u'] = 'g';         mp['i'] = 'c';      mp['o'] = 'r';
     mp['p'] = 'l';         mp['['] = '/';      mp[']'] = '=';
     mp['\\'] = '\\';       mp['a'] = 'a';      mp['s'] = 'o';
     mp['d'] = 'e';         mp['f'] = 'u';      mp['g'] = 'i';
     mp['h'] = 'd';         mp['j'] = 'h';      mp['k'] = 't';
     mp['l'] = 'n';         mp[';'] = 's';      mp['\''] = '-';
     mp['z'] = ';';         mp['x'] = 'q';      mp['c'] = 'j';
     mp['v'] = 'k';         mp['b'] = 'x';      mp['n'] = 'b';
     mp['m'] = 'm';         mp[','] = 'w';      mp['.'] = 'v';
     mp['/'] = 'z'; 

     mp['~'] = '~';         mp['!'] = '!';      mp['@'] = '@';
     mp['#'] = '#';         mp['$'] = '$';      mp['%'] = '%';
     mp['^'] = '^';         mp['&'] = '&';      mp['*'] = '*';
     mp['('] = '(';         mp[')'] = ')';      mp['_'] = '{';
     mp['+'] = '}';    

     mp['`'] = '`';         mp['-'] = '[';      mp['='] = ']';   
     mp['1'] = '1';         mp['2'] = '2';      mp['3'] = '3';
     mp['4'] = '4';         mp['5'] = '5';      mp['6'] = '6';
     mp['7'] = '7';         mp['8'] = '8';      mp['9'] = '9';
     mp['0'] = '0';         mp[' '] = ' ';
}
int main()
{
    string s;
    solve();
    while(getline(cin,s))
    {
              for (int i = 0; i < s.size(); i++)
              {
                  cout << mp[s[i]];
              }
              cout << endl;
    }
}