#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <tchar.h>
#include <windows.h>
int rnd(int a,int b)
{
    return rand() / (double)RAND_MAX * (b - a + 1) + a;
}
int main(void)
{
    time_t t = time(0);
    srand(t);
    FILE * fread =  fopen("Input.txt","w+");
    freopen("Input.txt","r",stdin);
    FILE * fp = freopen("Output.txt","w",stdout);
    for(int i = 0; i < 20; i++)
    {
        int t = rnd(1,100);
        fprintf(fread,"%d\n",t);
        for(int i = 0; i < t; i++)
        {
            int o = rnd(0,10),m = rnd(1,500),n = rnd(0,100);
            fprintf(fread,"%d %d %d\n",o,m,n);
            for(int j = 0; j < n; j++)
            {
                int a = rnd(1,m);
                int b = rnd(1,m);
                int c = rnd(0,100);
                int d = rnd(0,10);
                fprintf(fread,"%d %d %d %d\n",a,b,c,d);
            }
            fprintf(fread,"\n");
        }

    }
    fclose(fread);

    PROCESS_INFORMATION pi;
    STARTUPINFO si = {0};
    si.cb = sizeof(si);
    si.wShowWindow = SW_SHOW;
    si.dwFlags = STARTF_USESHOWWINDOW;

    for(int i = 0; i < 20; i++)
    {
        int s = CreateProcess(NULL,_T("test.exe"),NULL,NULL,1,0,NULL,NULL,&si,&pi);
        WaitForInputIdle(pi.hProcess,INFINITE);
    }
    return 0;
}
