#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 10010
struct node {
    int a, b;

}p[N];
bool cmp(node x, node y)
{
    return x.b < y.b;             //�߶�β������
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n; i++) {
        scanf("%d%d",&p[i].a,&p[i].b);
    }
    sort(p, p+n, cmp);
    int k = 1;                    //��Ϊ��ʼ����ĵ�һ���߶ο϶������� 
    int ans = p[0].b;
    for(int i = 1;i < n; i++) {
        if(ans <= p[i].a) {       //�����ν�������С�ڵ��� 
            k++;
            ans = p[i].b;
        }
    }
    printf("%d\n",k);
	return 0;
}
