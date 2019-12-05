#include <cstdio>

int main(void) {
	int a, b;
	while (scanf("%d %d", &a, &b)!= EOF) {   //或者 while (~scanf("%d%d", &a, &b)) 
		printf("%d\n", a + b);
	}
	
	return 0;
}
