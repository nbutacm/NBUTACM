#include <cstdio>
#include <cctype>
#include <cstring>

char str[100];

int main(void) {
    int t;
    scanf("%d", &t);
    getchar();
    while (t--) {
        fgets(str, 100, stdin);
        str[strlen(str) - 1] = '\0';
        int flag = 0;
        if (!(islower(str[0]) || isupper(str[0]) || str[0] == '_')) {
            flag = 1;
        } else {
            int sum = 0;
            for (int i = 0; i < strlen(str); i++) {
                if (str[i]>='0'&&str[i]<='9'||str[i]>='a'&&str[i]<='z'||str[i]>='A'&&str[i]<='Z'||str[i]=='_') {
                    sum++;
                }
            }
            if (sum != strlen(str)) flag = 1;
        }
        if (!flag) printf("yes\n");
        else printf("no\n");
    }

    return 0;
}
