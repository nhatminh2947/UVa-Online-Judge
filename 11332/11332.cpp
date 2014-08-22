#include  <cstdio>

int F(int n)
{
    int result;
    if(n>=10)
    {
        while(n>=10)
        {
            result=0;
            while(n)
            {
                result+=n%10;
                n/=10;
            }
            n=result;
        }
        return result;
    }
    else return n;
}


int main()
{
    int n,g=0;    
    freopen("11332.INP","r",stdin);
    freopen("11332.OUT","w",stdout);
    while(scanf("%d",&n) && n)
    {
        g = F(n);
        printf("%d\n",g);
    }
    return 0;
}
