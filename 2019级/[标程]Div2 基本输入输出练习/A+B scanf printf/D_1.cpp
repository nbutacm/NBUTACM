#include <cstdio>
#include <cstring>

int main(void) {
	int n;
	while (scanf("%d", &n) != EOF && n != 0) {
		int ans = 0, a;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a);
			ans += a;
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
