//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 10534 - Wavio Sequence
//==============================================================

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <climits>
#define INF 999999999

using namespace std;

int data[10005];
int L[10005],Lu[10005];
int StartOf[10005];
int n,m;

int init()
{
    m=1;
    L[1]=1;
    StartOf[1]=1;
}        

int Find(int i)
{
    int inf,sup,median,j;
    inf=1;
    sup=m+1;
    while((inf+1)!=sup)
    {
        median=(inf+sup)/2;
        j=StartOf[median];
        if(data[j]<data[i])
            inf=median;
        else sup=median;
    }
    return StartOf[inf];
}        

void DP()
{
    int j,k;
    for(int i=2;i<=n;i++)
    {
        j=Find(i);
        if(data[i]>data[j])
            k=L[j]+1;
        else
            k=L[j]-L[1]+1;
        if(k>m)
        {
            m=k;
            StartOf[k]=i;
        }
        else if(data[StartOf[k]]>data[i])
            StartOf[k]=i;
        L[i]=k;
    }
}

int main()
{
    //freopen("10534.INP","r",stdin);
    //freopen("10534.OUT","w",stdout);
    while(scanf(" %d " ,&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf(" %d ",&data[i]);
            
        init();
        DP();
        for(int i=1;i<=n;i++)
            Lu[i]=L[i];
        reverse(data+1,data+n+1);
        
        init();
        DP();
        reverse(L+1,L+n+1);
        
        int ans=-1;
        for(int i=1;i<=n;i++)
            ans=max(ans,min(Lu[i],L[i]));
        printf("%d\n",ans*2-1);
    }
    return 0;
}
