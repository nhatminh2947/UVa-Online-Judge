//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 908 - Re-connecting Computer Sites
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
#define INF 99999999

using namespace std;

typedef struct
{
    int u,v,c;
}edge;

edge data[1000005];
int lab[1000005];
int n,k,m;

int getRoot(int u)
{
    if(lab[u]==u) return u;
    return lab[u]=getRoot(lab[u]);
}

int unionset(int a,int b)
{
    return lab[a]=b;
}

bool cmp(edge a,edge b)
{
    return a.c<b.c;
}

int main()
{
    //freopen("908.INP","r",stdin);
    //freopen("908.OUT","w",stdout);
    int tcs=0;
    while(scanf(" %d ",&n)!=EOF)
    {
        if(tcs++) printf("\n");
        int sum=0;
        int cnt=0;
        for(int i=1;i<=n;i++)
            lab[i]=i;
        for(int i=1;i<=n-1;i++)
        {
            scanf(" %d %d %d ",&data[cnt].u,&data[cnt].v,&data[cnt].c);
            sum+=data[cnt].c;
            cnt++;
        }
        scanf(" %d ",&k);
        for(int i=1;i<=k;i++)
        {
            scanf(" %d %d %d ",&data[cnt].u,&data[cnt].v,&data[cnt].c);
            cnt++;
        }
        scanf(" %d ",&m);
        for(int i=1;i<=m;i++)
        {
            scanf(" %d %d %d ",&data[cnt].u,&data[cnt].v,&data[cnt].c);
            cnt++;
        }
        sort(data,data+cnt,cmp);
        int M=0,cost=0;
        for(int i=0;i<cnt;i++)
        {
            int u=data[i].u;
            int v=data[i].v;
            int c=data[i].c;
            
            int r1=getRoot(lab[u]);
            int r2=getRoot(lab[v]);
            
            if(r1!=r2)
            {
                M++;
                cost+=c;
                unionset(r1,r2);
            }
            if(M==(n-1)) break;
        }
        printf("%d\n%d\n",sum,cost);
    }
    return 0;
}
