#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
char str[100];

int main(void) {
    int n;
    cin >> n;
    getchar();
    while (n--) {
        cin.getline(str, 100);
        int flag = 0;
        if (!(isalpha(str[0]) || str[0] == '_')) {
            flag = 1;
        } else {
            int len = strlen(str);
            for (int i = 0; i < len; i++) {
                if (!(isalpha(str[i]) || str[i] == '_' || isalnum(str[i]))) {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag) cout <<  "no" << endl;
        else cout << "yes" << endl;
	}

    return 0;
}
