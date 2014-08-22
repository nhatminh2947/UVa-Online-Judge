#include <iostream>
#include <cstdio>

using namespace std;

int a[105][105];
int n,d_u,d_v;
long int max(int s_d,int f_d,int s_c,int f_c)
{
    long int tong=0;
    for (int i=s_d;i<=f_d;i++)
    for (int j=s_c;j<=f_c;j++) tong+=a[i][j];
    return tong;
}

int main ()
{
    freopen("108.INP","r",stdin);
    freopen("108.OUT","w",stdout);


    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) scanf("%d",&a[i][j]);
        
    long int tmp=-99999999;    
    for (int i=1;i<=n;i++)
    for (int j=i;j<=n;j++)        
    if (max(1,n,i,j)>=tmp) { tmp=max(1,n,i,j); d_u=i; d_v=j; }
    tmp=-99999999;    
    for (int i=1;i<=n;i++)
    for (int j=i;j<=n;j++)        
    if (max(i,j,d_u,d_v)>=tmp) tmp=max(i,j,d_u,d_v);

    printf("%d",tmp);
    return 0;    
}
