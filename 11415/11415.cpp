#include "cstdio"
#include "math.h"

int T;
long long n;
long long num[10000000];
long long ans[10000010];

int sieve()
{
    for(long long i=2;i<=3000000;i++)
        num[i]=0;
        
    for(long long i=2;i<=3000000;i++)
        if(num[i]==0)
            for(long long j=i;j<=3000000;j*=i)
                for(long long k=1;k*j<=3000000;k++)
                    num[j*k]++;
    
    num[0]=0;
    num[1]=0;
    for(long long i=2;i<=3000000;i++)
        num[i]+=num[i-1];
    ans[1]=3;
    long long k=3;
    for(long long i=2;i<=10000000;i++)
    {
        if(num[k]<=i)
        {
            ans[i]=ans[i-1]+1;
            k++;
        }
        else ans[i]=ans[i-1];
    }
}

int main()
{
    freopen("11415.INP","r",stdin);
    freopen("11415.OUT","w",stdout);
    scanf("%d",&T);
    sieve();
    for(int i=1;i<=T;i++)
    {
        scanf("%lld",&n);
        printf("%lld\n",ans[n]);
    }
    return 0;
}
