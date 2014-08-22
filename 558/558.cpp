//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 558 - Wormholes
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
#define INF 2147483647

using namespace std;

struct edges
{
    int s,e,w;
} wh[2000 + 5];

int dist[1000+5];
int c,n,m;

int main()
{
    //freopen("558.INP","r",stdin);
    //freopen("558.OUT","w",stdout);
    scanf("%d",&c);
    for(int i=0;i<c;i++)
    {
        scanf("%d%d",&n,&m);
        for(int j=0;j<m;j++)
            scanf("%d%d%d",&wh[j].s,&wh[j].e,&wh[j].w);
        for(int j=0;j<n;j++) dist[j]=INF;
        dist[0]=0;
        for(int j=0;j<n-1;j++)
            for(int k=0;k<m;k++) 
                if(dist[wh[k].s]+wh[k].w<dist[wh[k].e])
                    dist[wh[k].e]=dist[wh[k].s]+wh[k].w;
        bool check=false;
        for(int j=0;j<m;j++)
            if(dist[wh[j].s]+wh[j].w<dist[wh[j].e])
                check=true;
        if(check) printf("possible\n");
        else printf("not possible\n");
    }
    return 0;
}
