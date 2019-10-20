#include<bits/stdc++.h>
using namespace std;
int l,i,f;  char s[201],k[201];
int main()
{
    while(~scanf("%s",s))
    {
        l=strlen(s)-1;
        
        while(s[i++]=='9')
            if(i==l+1)
                for(s[0]='1',l++;i>0;i--)
                    s[i]='0';

        for(i=0;i<=l-i;i++)
            k[i]=k[l-i]=s[i];

        if(strcmp(k,s)<=0)
        {
            while(k[--i]=='9');
            k[i]=k[l-i]=++k[i];
            for(i++;i<=l-i;i++)
                k[i]=k[l-i]='0';
        }

        cout<<k<<endl;
    }
    return 0;
}