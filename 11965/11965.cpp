#include "cstdio"
#include "string.h"

int T,n;
char s[505];

int handle()
{
    int k=strlen(s);
    for(int i=0;i<k;i++)
    {
        if(s[i+1]!='\0' && s[i]==' ' && s[i+1]==' ')
        {
            for(int j=i;j<k;j++)
                s[j]=s[j+1];
            k--;
            i--;
        }
    }
}

int main()
{
    //freopen("11965.INP","r",stdin);
    //freopen("11965.OUT","w",stdout);
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        scanf("%d",&n);
        printf("Case %d:\n",i);
        getchar();
        for(int j=1;j<=n;j++)
        {
            gets(s);
            handle();
            puts(s);
        }
        if(i!=T) printf("\n");
    }
}
