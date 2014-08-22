#include "cstdio"
#include <string.h>
#include <stdlib.h>

int GCD(int a,int b)
{
    if(b)
        return GCD(b,a%b);
    return a;
}

int main()
{
    freopen("11827.INP","r",stdin);
    freopen("11827.OUT","w",stdout);
    char s[100],N;
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        scanf(" ");
        gets(s);
        int j=1,k=0,max=0;
        int num[105];
        while(s[k])
        {
            num[j]=0;
            while(s[k]&&s[k]!=' ')
            {
                num[j]=num[j]*10+s[k]-'0';
                k++;
            }
            while(s[k]==' ')
                k++;
            j++;
        }
        for(int p=1;p<=j;p++)
            for(int q=p+1;q<j;q++)
                if (max<GCD(num[p],num[q])) max=GCD(num[p],num[q]);
        printf("%d\n",max);
    }
    return 0;
}

