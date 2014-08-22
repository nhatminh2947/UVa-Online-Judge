#include "cstdio"
#include "math.h"

bool primes[5000007];
bool deprimes[5000007];
int temp[5000007];
int ans[5000007];
int a,b;

int sieve()
{
    int k=0;
    for(int i=0;i<=5000000;i++)
    {
        primes[i]=true;
        temp[i]=0;
        deprimes[i]=false;
    }
    for(int i=2;i<=5000000;i++)
        if(primes[i]==true)
            for(int j=1;j*i<=5000000;j++)
            {
                if(j!=1) primes[i*j]=false;
                temp[i*j]+=i;
            }
    for(int i=2;i<=5000000;i++)
        if(primes[temp[i]]==true) 
            deprimes[i]=true;
    ans[2]=1;
    for(int i=3;i<=5000000;i++)
        if(deprimes[i]==true) ans[i]=ans[i-1]+1;
        else ans[i]=ans[i-1];
}

int main()
{
    freopen("11408.INP","r",stdin);
    freopen("11408.OUT","w",stdout);
    sieve();
    while(scanf("%d%d",&a,&b) && a && b)
        if(deprimes[a]==true) printf("%d\n",ans[b]-ans[a]+1);
        else printf("%d\n",ans[b]-ans[a]);
    return 0;
}
