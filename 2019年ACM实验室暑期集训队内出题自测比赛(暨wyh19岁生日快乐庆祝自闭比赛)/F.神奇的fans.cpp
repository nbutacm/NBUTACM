#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    int m, a[105];
    while(T--)
    {
        cin >> m;
        for(int i = 0; i < m; i++)
            cin >> a[i];
        sort(a, a + m);
        int temp = a[1] - a[0];
        bool flag = true;
        for(int i = 2; i < m; i++)
        {
            if(a[i] - a[i-1] != temp)
            {
                flag = false;
                break;
            }
        }
        if(flag) cout << "yes"<< endl;
        else cout << "no" << endl;
    }
}