//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 10154 - Weights and Measures
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
#define INF 999999999

using namespace std;

typedef struct
{
    int w,sth;
}turtle;

turtle t[5617];
int c[5617];
int n=1;

bool cmp(turtle a,turtle b)
{
    return a.sth<b.sth;
}

void DP()
{
    for(int i=0;i<=n;i++)
        c[i]=INF;
    c[0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j>=1;j--)
        {
            if(c[j-1]<=t[i].sth)
                c[j]=min(c[j],c[j-1]+t[i].w);
        }
    }
}

int main()
{
    //freopen("10154.INP","r",stdin);
    //freopen("10154.OUT","w",stdout);
    
    n=1;
    while(scanf(" %d %d ",&t[n].w,&t[n].sth)==2)
    {
        t[n].sth-=t[n].w;
        n++;
    }
    n--;
    sort(t+1,t+n+1,cmp);
    DP();
    int res;
    int cnt;
    for(cnt=n;cnt>=1;cnt--)
        if(c[cnt]<INF)
        {
            res=cnt;
            break;
        }
    printf("%d\n",res);
    return 0;
}
