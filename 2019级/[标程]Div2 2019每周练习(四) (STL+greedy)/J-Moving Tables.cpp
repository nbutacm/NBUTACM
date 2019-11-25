#include<iostream>
#include<cstring>
using namespace std;
int main() {
	int t;
	cin>>t;
	int sz[205];
	while(t--) {
		int start,end,num,max=0;
		cin >> num;
		memset(sz,0,sizeof(sz));
	    while(num--) {
	    	cin >> start >> end ;
	    	if(start > end) {
	    		swap(start,end);
			}
			if(start % 2 == 1) start += 1;
			if(end % 2 == 1) end += 1;
	    	for(int i=start / 2;i <= end / 2 ; i++)
	    		sz[i]++;
		}
		for(int i=0;i<205;i++) {
			if(max < sz[i]) max = sz[i];
		}
		cout<< max*10 <<endl;
	}
	return 0;
 } 
