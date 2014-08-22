#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int T;
char str[50],s[7];

int main()
{
    freopen("12403.INP","r",stdin);
    freopen("12403.OUT","w",stdout);
    scanf("%d",&T);
    int K=0,tong=0;
    for(int i=1;i<=T;i++)
    {
        scanf(" ");
        gets(str);
        sscanf(str,"%s%d",s,&K);
        if (strcmp(s,"report")==0) printf("%d\n",tong);
        else if ((strcmp(s,"donate")==0) && (100<=K) && (K<=100000)) tong=tong+K;
    }
    return 0;
}
