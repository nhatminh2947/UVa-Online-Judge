//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 11228 - Transportation system.
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
    int x,y;
}coordinates;

typedef struct
{
    int u,v;
    double c;
}edge;

edge data[510000];
coordinates xy[1005];
int lab[510000];
int tcs,n,r;

float weight(int a,int b)
{
    return sqrt((xy[a].x-xy[b].x)*(xy[a].x-xy[b].x)+(xy[a].y-xy[b].y)*(xy[a].y-xy[b].y));
}

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
    //freopen("11228.INP","r",stdin);
    //freopen("11228.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int i=1;i<=tcs;i++)
    {
        scanf(" %d %d ",&n,&r);
        for(int j=0;j<n;j++)
            scanf(" %d %d ",&xy[j].x,&xy[j].y);
        int cnt=0;
        for(int j=0;j<n-1;j++)
            for(int k=j+1;k<n;k++)
            {
                data[cnt].u=j;
                data[cnt].v=k;
                data[cnt].c=weight(j,k);
                cnt++;
            }
        sort(data,data+cnt,cmp);
        
        for(int j=0;j<n;j++)
            lab[j]=j;
            
        int done=0,state=0;
        double rail=0,road=0;
        for(int j=0;j<cnt;j++)
        {
            int u=data[j].u;
            int v=data[j].v;
            double c=data[j].c;
            
            int r1=getRoot(lab[u]);
            int r2=getRoot(lab[v]);
            
            if(r1!=r2)
            {
                if(c>r) 
                {
                    rail+=c;
                    state++;
                }
                else road+=c;
                done++;
                unionset(r1,r2);
            }
            if(done==(cnt-1)) break;
        }
        
        printf("Case #%d: %d %.lf %.lf\n",i,state+1,road,rail);
    }
    return 0;
}
