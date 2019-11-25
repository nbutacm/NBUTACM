#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int main() {
	int n,m;
	int a[70000];
	while(cin >> n >> m) {
		memset(a,0,sizeof(a));
		queue<int>que;
		for(int i=0;i< 2*n ;i++) {
			a[i] = 1;
			que.push(i); 
		}
		int sum = 0;
		while(que.size() != n) {
			int x = que.front();
			sum++;
			if(sum == m) {
				que.pop();
				a[x] = 0;
				sum = 0;
			}
			else {
				que.pop();
				que.push(x); 
			}
		}
		for(int i = 0;i< 2*n ;i++) {
			if(a[i] == 1 ) cout << "G";
			else  cout << "B";
			if((i + 1) % 50 == 0) cout << endl;
		}
		cout << endl << endl;
	}
	return 0;
}

