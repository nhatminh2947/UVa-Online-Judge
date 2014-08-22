#include "stdio.h"
#include "stdlib.h"

int T,a,b,c;

int main()
{
    freopen("11727.INP","r",stdin);
    freopen("11727.OUT","w",stdout);
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        if ((c<a && a<b)||(b<a && a<c)) printf("Case %d: %d\n",i,a);
        else if ((a<b && b<c)||(c<b && b<a)) printf("Case %d: %d\n",i,b);
        else printf("Case %d: %d\n",i,c);
    }
    return 0;
}
