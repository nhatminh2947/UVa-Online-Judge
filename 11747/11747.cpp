//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 11747 - Heavy Cycle Edges
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
    int u,v;
    long long c;
}edge;

edge data[25005];
long long check[1005][1005];
long long res[1005];
int lab[1005];
int n,m;

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
    //freopen("11747.INP","r",stdin);
    //freopen("11747.OUT","w",stdout);
    while(scanf(" %d %d ",&n,&m) && n)
    {
        for(int i=0;i<m;i++)
            scanf(" %d %d %d ",&data[i].u,&data[i].v,&data[i].c);
        sort(data,data+m,cmp);
        for(int i=0;i<n;i++)
        {
            lab[i]=i;
            for(int j=0;j<n;j++)
                check[i][j]=INF;
        }
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            int u=data[i].u;
            int v=data[i].v;
            long long c=data[i].c;
            
            int r1=getRoot(lab[u]);
            int r2=getRoot(lab[v]);
            
            //check[u][v]=check[v][u]=c;
            
            if(r1!=r2)
            {
                check[u][v]=check[v][u]=INF;
                unionset(r1,r2);
            }
            else res[cnt++]=c;
        }
        sort(res,res+cnt);
        bool lock=false;
        for(int i=0;i<cnt;i++)
        {
            if(lock) printf(" ");
            printf("%d",res[i]);
            lock=true;
        }
        if(!lock) printf("forest");
        printf("\n");
    }
    return 0;
}
