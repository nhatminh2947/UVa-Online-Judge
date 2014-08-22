#include "cstdio"
#include "string.h"
#include "ctype.h"

int T;
char in[205];


int LF()
{
    int a[27]={0};
    for(int i=0;i<strlen(in);i++)
        in[i]=tolower(in[i]);
    for(int i=0;i<strlen(in);i++)
        if('a'<=in[i] && in[i]<='z')
            a[in[i]-97]++;
    int max=a[0];
    for(int i=0;i<27;i++)
        if(max<a[i]) max=a[i];
    for(int i=0;i<27;i++)
        if(a[i]==max) 
            printf("%c",i+97);
    printf("\n");
}


int main()
{
    freopen("11577.INP","r",stdin);
    freopen("11577.OUT","w",stdout);
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        scanf(" ");
        gets(in);
        LF();
    }
}
