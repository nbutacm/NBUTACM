#include <iostream>
using namespace std;

int F[45];

int main()
{
	int n,i;
	F[1] = 0; 
	F[2] = 1;
	F[3] = 2;
	for(i=4;i<41;i++){
		F[i]=F[i-1]+F[i-2];     
	}
	cin >> n;
	while(n--){
		int m;
		cin >> m;
		cout << F[m] << endl;
	} 
	return 0;
}
