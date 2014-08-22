#include "stdio.h"
#include "stdlib.h"

int N,k,dem;
int a[105];
bool Tong[20005];

int main()
{
    //freopen("11063.INP","r",stdin);
    //freopen("11063.OUT","w",stdout);
    dem=0;
    while(scanf("%d",&N)!= EOF)
    {
        k=0;
        for(int i=0;i<=20005;i++)
            Tong[i]=false;
                               
        for(int i=1;i<=N;i++)
            scanf("%d",&a[i]);
        if (a[1]<1)
        {
            printf("Case #%d: It is not a B2-Sequence.\n", ++dem);
            goto NEXT;
        }
        for(int i=2;i<=N;i++)
            if(a[i]<=a[i-1]) 
            {
                printf("Case #%d: It is not a B2-Sequence.\n", ++dem);
                goto NEXT;
            }
        for(int i=1;i<=N;i++)
            for(int j=i;j<=N;j++)
            {
                if (Tong[a[i]+a[j]]==false)
                    Tong[a[i]+a[j]]=true;
                else
                {
                    printf("Case #%d: It is not a B2-Sequence.\n", ++dem);
                    goto NEXT;
                }
            }
        printf("Case #%d: It is a B2-Sequence.\n", ++dem);
        NEXT: ;
 		printf("\n");
    }
    return 0;
}
