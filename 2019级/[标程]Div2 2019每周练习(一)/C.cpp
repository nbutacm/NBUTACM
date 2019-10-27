#include <bits/stdc++.h>
using namespace std;

int main()
{
	double x1,y1,x2,y2;
	double s;
	while(scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2)!=EOF)
	{
		s=sqrt((x1-x2)*(x1-x2)*1.0+(y1-y2)*(y1-y2)*1.0);
		printf("%.2lf\n",s);
	}
		
}
