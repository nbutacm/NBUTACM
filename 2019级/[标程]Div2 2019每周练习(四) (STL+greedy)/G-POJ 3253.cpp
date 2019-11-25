#include<iostream>
#include<queue>
using namespace std;

int main(){
	priority_queue<int, vector<int>, greater<int> > que;
	int n,m;
	long long ans = 0;
	long long d=0;
	cin >> n;
	for(int i = 1; i <= n ; i++){
		cin >> m;
		que.push(m);
	}
	int t;
	while(que.size() > 1){
		t=que.top();
		que.pop();
		t += que.top();
		que.pop();
		que.push(t);
		ans += t;
	}
	cout << ans << endl;
	return 0;
} 
