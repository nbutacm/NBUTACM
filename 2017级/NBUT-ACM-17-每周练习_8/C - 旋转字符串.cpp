
// ���Կ���  �Դ�������ô��ת���ǶԴ�������ֻ���ж��Ե�һ���ַ����Ƿ��ǶԴ����� 

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
