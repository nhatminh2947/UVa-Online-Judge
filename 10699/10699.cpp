#include "cstdio"
#include "string.h"

int n;
bool prime[1000000];

int sieve()
{
    for(int i=0;i<1000000;i++)
        prime[i]=true;
    for(int i=2;i<=1000000;i++)
        for(int j=2;j*i<=1000000;j++)
            prime[i*j]=false;
}

int main()
{
    freopen("10699.INP","r",stdin);
    freopen("10699.OUT","w",stdout);
    sieve();
    while(scanf("%d",&n) && n)
    {
        int temp=n,count=0;
        for(int i=2;i<=temp;i++)
            if(prime[i]==true && temp%i==0)
                count++;
        printf("%d : %d\n",n,count);
    }
    return 0;
}
