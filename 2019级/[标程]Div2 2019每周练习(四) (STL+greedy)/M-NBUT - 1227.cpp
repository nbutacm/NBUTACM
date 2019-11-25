#include<cstdio>
#include<cstring>

int main() {
    char a[40];
    while (~scanf("%s",a)) {
        int len = strlen(a);
        long long sum = 0;
        int power = len - 1;
        for (int i = 0; i < len; i++, power--) {
            if (a[i] == '1') {
                sum += 1 << power;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
