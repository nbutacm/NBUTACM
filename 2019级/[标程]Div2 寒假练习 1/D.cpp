#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
char s[MAXN];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int q;
    cin>>q;
    while(q--)
    {
        cin >> s;
        int nl = 0, nr = 0, nu = 0, nd = 0;
        int n = strlen(s);
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'L') nl ++;
            else if(s[i] == 'R') nr ++;
            else if(s[i] == 'U') nu ++;
            else nd ++;
        }
        int anl = min(nl, nr);
        int anu = min(nu, nd);
        if(!anl && anu)
        {
            cout<<2<<endl<<"UD"<<endl;
            continue;
        }
        if(!anu && anl)
        {
            cout << 2 << endl << "LR" << endl;
            continue;
        }
        else if(!anl && !anu) cout << 0 << endl;
        else
        {
            cout <<2 * (anl + anu) << endl;
            for(int i = 0; i < anl; i++) cout << 'L';
            for(int i=0;i<anu;i++)  cout << 'U';
            for(int i=0;i<anl;i++)  cout << 'R';
            for(int i=0;i<anu;i++)  cout << 'D';
            cout << endl;
        }
    }
    return 0;
}
