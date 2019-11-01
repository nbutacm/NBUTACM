//#include"stdafx.h"
#include<vector>
#include<cstring>  
#include<sstream>
#include<iomanip>
#include <stdio.h>  
#include <iostream>
#include<queue>
#define MAXN 1000005
#define ll long long
using namespace std;
ll n, m, root[105 * 105];
const int N = 10005;
int link[N];
bool vis[N];
vector<int>v[N];

bool can(int u) {
	for (int i = 0; i < v[u].size(); i++) {
		int t = v[u][i];
		if (!vis[t]) {
			vis[t] = true;
			if (link[t] == -1 || can(link[t])) {
				link[t] = u;
				return true;
			}
		}
	}
	return false;
}

int max_match() {
	memset(link, -1, sizeof(link));
	int ans = 0;
	for (int i = 0; i < n; i++) {
		memset(vis, false, sizeof(vis));
		if (can(i))
			ans++;
	}
	return ans;
}


int main() {
	//freopen("/Users/cccccccccchy/compare/data.in","r",stdin);  
    //freopen("/Users/cccccccccchy/compare/data.out","w",stdout);

	int T;
	scanf("%d", &T);
	while (T--) {
		int  t = 0, num1, num2;
		string A, B;
		stringstream ss;
		cin >> n >> m;
		for (int i = 0; i <= n + m; i++)
			v[i].clear();
		while (1) {
			cin >> A;
			if (A == "0")
				break;
			cin >> B;
			if (A[0] == 'A') {
				ss.clear();
				A.erase(0, 1);
				ss << A;
				ss >> num1;
				B.erase(0, 1);
				ss.clear();
				ss << B;
				ss >> num2;
				v[num1].push_back(num2);
			}
			else if (A[0] == 'B') {
				ss.clear();
				A.erase(0, 1);
				ss << A;
				ss >> num1;
				B.erase(0, 1);
				ss.clear();
				ss << B;
				ss >> num2;
				vector<int>::iterator it = v[num2].begin();
				for (; it != v[num2].end();)
				{
					if (*it == num1)
						//删除指定元素，返回指向删除元素的下一个元素的位置的迭代器
						it = v[num2].erase(it);
					else
						//迭代器指向下一个元素位置
						++it;
				}
			}
		}
		int ans = 0;
		n = n + m;
		ans = max_match();
		printf("%d\n", ans);
	}
	return 0;
}
