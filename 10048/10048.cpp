//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 10048 - Audiophobia
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
    int u,v,cost;
}edge;

edge data[1005];
int lab[105];
int store[105][105];
int c,s,q,start,end,tcs=1,m;
bool vis[105];

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
    return a.cost<b.cost;
}

int solve(int a,int b,int max)
{
    if(a==b) return max;
    int k=-INF;
    for(int i=1;i<=c;i++)
    {
        if(!vis[i] && store[a][i]!=-INF)
        {
            vis[i]=true;
            
            if (max < store[a][i]) 
                k = solve(i,b,store[a][i]);
            else k = solve(i,b,max);
            
            if(k!=-INF)
                return k;
            vis[i]=false;
        }
    }
    return k;
}





int main()
{
    //freopen("10048.INP","r",stdin);
    //freopen("10048.OUT","w",stdout);
    bool lock=false;
    while(scanf(" %d %d %d ",&c,&s,&q) && c)
    {
        if(lock==true) printf("\n");
        lock=true;
        for(int i=0;i<s;i++)
            scanf(" %d %d %d ",&data[i].u,&data[i].v,&data[i].cost);
        for(int i=1;i<=c;i++)
        {
            lab[i]=i;
            for(int j=1;j<=c;j++)
                store[i][j]=-INF;
        }
        sort(data,data+s,cmp);
        int M=0;
        for(int i=0;i<s;i++)
        {
            int u=data[i].u;
            int v=data[i].v;
            int cost=data[i].cost;
            int r1=getRoot(u);
            int r2=getRoot(v);
            
            if(r1!=r2)
            {
                store[u][v]=cost;
                store[v][u]=cost;
                unionset(r1,r2);
                M++;
            }
            if(M==(c-1)) break;
        }
        printf("Case #%d\n",tcs++);
        for(int i=0;i<q;i++)
        {
            m=0;
            scanf(" %d %d ",&start,&end);
            for(int j=1;j<=c;j++)
                vis[j]=false;
            vis[start]=true;
            int res=solve(start,end,-INF);
            if(res==-INF) printf("no path\n");
            else printf("%d\n",res);
        }
    }
    return 0;
}
