#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<ctime>

#define FILE_INPUT 1    //�Ƿ����뵽�ļ�
#define MAX 100         //�������
#define N_M 100           //������ɵ���Ů��������޶�
#define T 100             //�����޶�
using namespace std;

int main()
{
    int ma[MAX][MAX];
    int t,x;
    int n,m;
    int a,b;
    srand(time(NULL));
#if FILE_INPUT
    fstream fs("in.txt",ios::out);
#endif // FILE_INPUT

    t = rand() % T + 1;

#if FILE_INPUT
    fs << t << endl;
#else
    cout << t << endl;
#endif

    while(t--){
        memset(ma,0,sizeof(ma));
        n = rand() % N_M + 1;
        m = rand() % N_M + 1;
#if FILE_INPUT
        fs << n << " " << m << endl;
#else
        cout << n << " " << m << endl;
#endif // FILE_INPUT

        int c = 0;
        while(true){
            x = rand() % 3;
            if(x == 0){
                if(c < n){
                    while(!x){
                        x = rand() % 3;
                    }
                }else{
#if FILE_INPUT
                    fs << x << endl;
#else
                    cout << x << endl;
#endif
                    break;
                }
            }

            a = rand() % n + 1;
            b = rand() % m + 1;

            if(x == 2){
                int t = a;
                a = b;
                b = t;
            }

            //ȥ�ظ�����
            if(ma[a][b] == x || ma[a][b] == 3){
                continue;
            }
            ma[a][b] += x;
#if FILE_INPUT
            fs << x << " " << a << " " << b << endl;
#else
            cout << x << " " << a << " " << b << endl;
#endif // FILE_INPUT

            c++;
        }
    }

#if FILE_INPUT
    fs.close();
#endif // FILE_INPUT

    return 0;
}
