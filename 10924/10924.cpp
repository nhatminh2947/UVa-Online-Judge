#include "cstdio"
#include "string.h"

char s[25];
bool prime[1205];

int sieve()
{
    for(int i=0;i<1200;i++)
        prime[i]=true;
    for(int i=2;i<=1200;i++)
        for(int j=2;j*i<=1200;j++)
            prime[i*j]=false;
}

int main()
{
    freopen("10924.INP","r",stdin);
    freopen("10924.OUT","w",stdout);
    sieve();
    while(scanf("%s",s)!=EOF)
    {
        int sum=0;
        for(int i=0;i<strlen(s);i++)
        {
            if('A'<=s[i] && s[i]<='Z') sum+=(s[i]-38);
            else if('a'<=s[i] && s[i]<='z') sum+=(s[i]-96);
        }
        if(prime[sum]==true) printf("It is a prime word.\n");
        else printf("It is not a prime word.\n");
    }
    return 0;
}
