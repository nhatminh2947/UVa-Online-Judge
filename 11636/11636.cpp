#include "cstdio"

int n;

int main()
{
    freopen("11636.INP","r",stdin);
    freopen("11636.OUT","w",stdout);
    int count=1;
    while((scanf("%d",&n)==1 && n>0))
    {
        int k=1,temp=2;
        while(temp<n)
        {
            temp*=2;
            k++;
        }
        if(n==1) k--;
        printf("Case %d: %d\n",count,k);
        count++;
    }
    return 0;
}
