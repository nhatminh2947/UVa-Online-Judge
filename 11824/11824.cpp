#include "cstdio"
#include "math.h"
int swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int main()
{
    freopen("11824.INP","r",stdin);
    freopen("11824.OUT","w",stdout);
    int T,land[45],save;
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        float sum=0;
        int k=1;
        for(int i=1;;i++)
        {
            scanf("%d",&land[i]);
            save=i;
            if(land[i]==0) break;
        }
        for(int i=1;i<save;i++)
            for(int j=i+1;j<save;j++)
                if(land[i]<land[j]) swap(&land[i],&land[j]);
        for(int i=1;i<save;i++)
            {
                sum+=(2*pow(land[i],k));
                k++;
            }
        if(sum<=5000000) printf("%.0f\n",sum);
        else printf("Too expensive\n");
    }
    return 0;
}
