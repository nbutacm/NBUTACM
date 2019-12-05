#include <cstdio>

int main(void) {
	int n;
	scanf("%d", &n);
	while (n--) {      //或者 for (int i = 1; i <= n; i++) 
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	} 
	
	return 0;
}
