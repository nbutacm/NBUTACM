
// 可以看出  对串无论怎么旋转都是对串，所以只用判断以第一个字符串是否是对串即可 

#include <iostream>
#include <cstring>
using namespace std;
char a[1000005];
int main()
{
    while(cin>>a)
    {
        int m=strlen(a);
        bool k=false;
        if(m%2!=0)
            cout<<"NO"<<endl;
        else
        {
            int n=m/2-1;
            for(int i=0;i<=n;i++)
            {
                if(a[i]!=a[i+n+1])
                {
                    k=true;
                    break;
                }
            }
            if(k==true)
                cout<<"NO"<<endl;
            else

                cout<<"YES"<<endl;
        }
    }
    return 0;
}
