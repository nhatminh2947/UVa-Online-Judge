#include "cstdio"
#include "math.h"

int san(int n,bool a[])
{
    for(int i=0;i<=n;i++)
        a[i]=true;
    a[1]=false;
    int k=1;
    while (k <= (int)sqrt(n))
    {
        k++;
        while (!a[k]) k++;
        int j = 2;
        while (k*j <= n)
        {
            a[k*j] = false;
            j++;
        }
    }
}

int cal(int n,bool a[])
{
    san(n,a);
    int dem=0;
    for(int i=2;i<=n;i++)
    {
        if(a[i]==true)
        {
            int count = 0;
            int k=i;              
            while(k<=n)
            {
                count+=n/k;
                k*=i;           
            }
            dem++;
            if(dem==16) printf("\n%9d",count); 
            else printf("%3d",count);  
        }
    }
}

int main()
{
    freopen("160.INP","r",stdin);
    freopen("160.OUT","w",stdout);    
    int n;
    
    while(scanf("%d",&n) && n)
    {
        bool a[n];
        printf("%3d! =",n);
        cal(n,a);
        printf("\n");
    }
    return 0;
}
