#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int a[2000005];
int n;

int main()
{
    freopen("11462.INP","r",stdin);
    freopen("11462.OUT","w",stdout);
    
    while(scanf("%d",&n) && n)
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n+1);
        for(int i=1;i<=n;i++)
            if(i!=n) printf("%d ",a[i]);
            else printf("%d\n",a[i]);
    }
    return 0;
}
