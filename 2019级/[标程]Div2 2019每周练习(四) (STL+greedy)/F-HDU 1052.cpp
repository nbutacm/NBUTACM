#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(int x,int y) {
	return x>y;
}

int main() {
	int tj[1010],gw[1010],n,i;
	while(cin >> n) {
		if(n == 0) return 0;
		for(i=0;i<n;i++)
		    cin>>tj[i];
		for(i=0;i<n;i++)
		    cin>>gw[i];
		sort(tj,tj+n,cmp);
		sort(gw,gw+n,cmp);
		int t1=0,t2=0,w1=n-1,w2=n-1,sum=0;
		while(t1 <= w1) {
		  if(tj[t1] > gw[t2]) {
			  sum += 200;
		      t1++;
			  t2++;
		  }
		  else if(tj[t1] < gw[t2]) {
			  sum -= 200;
			  t2++;
			  w1--;
		  }
		  else{
			  if(tj[w1] > gw[w2]) {
				  sum += 200;
				  w1--;
				  w2--;
			  }
			  else{
				  if(tj[w1] < gw[t2]) sum-=200;
			      w1--;
			      t2++;
			  }
		  }
		}
		cout << sum << endl;
	}
	return 0;
} 
