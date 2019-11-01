#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int m,n;
	char a[105][105];
	while(cin >> m >> n){
		if(m==0 && n==0){
			break;
		}
		int num=0;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin >> a[i][j];
				if(a[i][j]=='*'){
					num++;
				}
			}
		}
		cout << num << endl;
	}
	return 0;
}




