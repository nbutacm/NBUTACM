#include<bits/stdc++.h>
using namespace std;
char sl[27]="abcdefghijklmnopqrstuvwxyz";
#define random(a,b) ((a)+rand()%((b)-(a)+1))
stringstream ss;
int main(int argc, char *argv[]){
	int seed=time(NULL);
	if(argc)
	{
		ss.clear();
		ss<<argv[1];
		ss>>seed;
	}
	srand(seed);
	ofstream file("in.txt",ios::app);
	srand((unsigned)time(NULL));
	for(int k=0;k<10;k++){
		int n=random(1,1000);
		file<<n<<endl;
		cout<<n<<endl;
		string ss;
		for(int i=0;i<n;i++){
			ss+=sl[random(0,25)];
		}
		cout<<ss<<endl<<endl;
		file<<ss<<endl<<endl;
	}

	file.close();
}
