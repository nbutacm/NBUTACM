//һ����n�죬ÿ7��Ϊһ�ܣ�����������Ϣ������һ������ں���̼���
    
#include<iostream>      
using namespace std;  
  
int n;  
int maxn, minn;  
  
int main()  
{  
    scanf("%d", &n);
    int k = n / 7;  
    int s = n % 7;  
    maxn = minn = k * 2;  
    if (s != 0) {  
        if (s == 1) maxn++;  
        else if (s == 6) {  
            minn++;  
            maxn += 2;  
        }  
        else maxn += 2;  
    }  
    printf("%d %d\n", minn, maxn);  
    return 0;  
}  
