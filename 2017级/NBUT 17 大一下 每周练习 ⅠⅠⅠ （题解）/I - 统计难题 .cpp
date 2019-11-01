#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <map>
#include <cmath>
#define FAST_IO ios::sync_with_stdio(false)
#define clr(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
const double pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+30;

map<string,int>M;

int main(){
	string s,t;
	int l;
	while(getline(cin,s)){
		if(s=="") break;
		t = "";
		l = s.length();
		for(int i=0;i<l;i++){
			t += s[i];
			M[t]++;
		}
	}
	while(cin >> s){
		cout << M[s] << endl;
	}
	return 0;
}


// 字典树

#include <iostream>
#include <stdio.h>
using namespace std;

int trie[1000010][26];    //数组形式定义字典树，值存储的是下一个字符的位置
int num[1000010]={0};    //附加值，以某一字符串为前缀的单词的数量
int pos = 1;

void Insert(char word[])    //在字典树中插入某个单词
{
    int i;
    int c = 0;
    for(i=0;word[i];i++){
        int n = word[i]-'a';
        if(trie[c][n]==0)    //如果对应字符还没有值
            trie[c][n] = pos++;
        c = trie[c][n];
        num[c]++;
    }
}
int Find(char word[])    //返回以某个字符串为前缀的单词的数量
{
    int i;
    int c = 0;
    for(i=0;word[i];i++){
        int n = word[i]-'a';
        if(trie[c][n]==0)
            return 0;
        c = trie[c][n];
    }
    return num[c];
}

int main()
{
    char word[11];
    while(gets(word)){
        if(word[0]==NULL)    //空行。gets读入的回车符会自动转换为NULL。
            break;
        Insert(word);
    }
    while(gets(word))
        printf("%d\n",Find(word));
    return 0;
}