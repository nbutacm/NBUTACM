#include<iostream>
#include<cstring>
using namespace std;
char str[55];
int main(){
	int n;
	cin >> n
	getchar();
	while(n--){
		gets(str);
		if ((str[0] >= '0'&&str[0] <= '9' ) || str[0] == 32){
			cout << "no" << endl;
			continue;
		}
		else {
			int flag = 1; 
			for(int i = 0 ;i < strlen(str) ;i++){
				if (str[i] == '_' || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9')) { 
					continue;
				} else {
					flag = 0;
					break;
				}
			}
			if(flag == 1 ){
				cout << "yes" << endl;
				continue;
			} else {
				cout << "no" << endl;
			} 
		}
    }
	
	return 0;
}
