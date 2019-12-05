#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n;
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        if (n == 1) {
            cout << "小郁是个大骗子！！！" << endl;
            continue;
        }
        cout << n << " " << n+1 << " " << n*(n+1) << endl; 
         
    }
    return 0;
} 
