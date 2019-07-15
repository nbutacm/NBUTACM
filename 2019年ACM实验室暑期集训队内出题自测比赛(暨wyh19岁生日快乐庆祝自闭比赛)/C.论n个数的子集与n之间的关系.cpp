/*********************************************************************************************************/


#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define pause system("pause");
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;
int y[10005],a[10005];
int main(void) {
    FAST_IO;
    int t,n,m;
    cin >> t;
    while(t--){
        ll sum = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << "Yes" << endl;
    }
    //  pause;
    return 0;
}

/*********************************************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
    #include<algorithm>
using namespace std;
int t,n,f[10005],a[10005];
int main()
{
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        memset(f,false,sizeof(f));
        memset(a, 0, sizeof(a));
        bool flag = false;
        for (int i = 1; i <= n;i++)
        {
            scanf("%d", &a[i]);
            a[i] = a[i] % n;
            if (a[i]==0)
            {
                flag = true;
            }
            //f[a[i]] = true;
        }
        if (flag) 
        {
            puts("Yes");
            continue;
        }
        f[0] = true;
        for (int i = 1; i <= n;i++)
        {
            for (int j = n; j >= a[i];j--)
            {
                f[i] = f[j - a[i]];
            }
            if (f[n])
                puts("Yes");
            else
                puts("No");
        }
            
    }
    return 0;
}