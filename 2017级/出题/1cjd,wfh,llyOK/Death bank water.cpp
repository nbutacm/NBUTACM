#include <iostream>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include <fstream>
using namespace std;

int main(){
	int t;
	double v;
	scanf("%d",&t);
	while(t--){
		scanf("%lf",&v);
		double a=pow(2*v,1.0/3);
		double b=pow(2*v,1.0/3);
		double h=pow(2*v,1.0/3)/2;
		printf("%.2f %.2f %.2f\n",a,b,h);
	}
	return 0;
}

