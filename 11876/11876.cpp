#include "cstdio"
#include "math.h"
int divnum[1000005];
int nod[1000005];
int ans[1000005];
bool check[1000005];

int sieve()
{
    for(int i=0;i<=1000000;i++)
    {
        divnum[i]=1;
        check[i]=false;
    }
    for(int i=2;i<=1000000;i++)
        for(int j=1;j*i<=1000000;j++)
            divnum[j*i]++;
    nod[1]=1;
    check[1]=true;
    int k=2;
    for(int i=1;i<=1000000;i++)
        if(nod[k-1]==i)
        {
            check[divnum[i]+i]=true;
            nod[k]=divnum[i]+i;
            k++;
        }
}

int count()
{
    ans[1]=1;
    ans[2]=2;
    int k=3;
    for(int i=3;i<=1000000;i++)
    {
        if(nod[k]<=i)
        {
            ans[i]=ans[i-1]+1;
            k++;
        }
        else ans[i]=ans[i-1];
    }
}
    

int main()
{
    freopen("11876.INP","r",stdin);
    freopen("11876.OUT","w",stdout);
    int a,b,T;
    sieve();
    count();
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        scanf("%d%d",&a,&b);
        if(check[a]==false) printf("Case %d: %d\n",i,ans[b]-ans[a]);
        else printf("Case %d: %d\n",i,ans[b]-ans[a]+1);
    }
    return 0;
}
