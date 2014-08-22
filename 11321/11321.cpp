//============================
// Name: Huynh Nhat Minh
// Problem Number: 11321
//============================

#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

int n;
long long num[10005],m;

bool cmp(long long a,long long b)
{
    if(a%m!=b%m) return a%m<b%m;
    else
    {
        if(abs(a)%2==0 && abs(b)%2==0) return a<b;
        else if(abs(a)%2==1 && abs(b)%2==1) return a>b;
        else return abs(a%2)>abs(b%2);
    }
}

int main()
{
    freopen("11321.INP","r",stdin);
    freopen("11321.OUT","w",stdout);
    while(scanf("%d%lld",&n,&m))
    {
        if(n==0 && m==0) 
        {
            printf("0 0\n");
            break;
        }
        for(int i=0;i<n;i++)
            scanf("%lld",&num[i]);
        sort(num,num+n,cmp);
        printf("%d %lld\n",n,m);
        for(int i=0;i<n;i++)
            printf("%lld\n",num[i]);
    }
    return 0;
}
