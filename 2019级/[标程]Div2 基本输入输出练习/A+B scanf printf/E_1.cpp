#include <cstdio>

int main(void) {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, a;
		scanf("%d", &n);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a);
			ans += a;
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
