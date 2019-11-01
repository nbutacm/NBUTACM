#include<iostream>
using namespace std;
#define INF 1000000000
int main()
{
    int l,n,c,t,vr,v1,v2,p[110];
    double t1,t2,dp[110],min;  
    int i,j,temp;
    while(cin>>l)
    {
        scanf("%d%d%d%d%d%d",&n,&c,&t,&vr,&v1,&v2);
        for(i=1;i<=n;i++)
            cin>>p[i];   
        p[0]=0;   
         p[n+1]=l;  
         dp[0]=0;
        for(i=1;i<=n+1;i++)
        {
            min=INF;
            for(j=0;j<i;j++)
            
            {
                temp=p[i]-p[j];
                if(temp>c)
                    t2=1.0*c/v1+1.0*(temp-c)/v2;
                else
                    t2=1.0*temp/v1;
                t2+=dp[j];
                if(j)  
                    t2+=t;
                if(min>t2)   
                    min=t2;
                
            }
            dp[i]=min;
        }
        t1=1.0*l/vr;   
         if(t1>dp[n+1])
            printf("What a pity,CaoCao!\n");
        else
            printf("Good job,CaoCao!\n");
    }
    return 0;
}
