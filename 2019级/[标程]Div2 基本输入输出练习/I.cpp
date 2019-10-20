#include <cstdio>
#define MAXN 100 + 10
#define INF 0x3f3f3f3f
int a[MAXN];

int main(void) {
	int n;
	
	while (scanf("%d", &n) != EOF) {
		if (n == 0) break;
		int Min = INF, pos = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			if (a[i] < Min) {
				Min = a[i];
				pos = i;
			}
		}
		int temp = a[0];
		a[0] = a[pos];
		a[pos] = temp;
		for (int i = 0; i < n; i++) {
			printf(i == 0 ? "%d" : " %d", a[i]);
		}
		printf("\n");
	}
	
	return 0;
}
