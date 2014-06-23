//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 10801 - Lift Hopping
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

using namespace std;

int num,n,to,delay,start,end;
int tcs=0;
int vis[1000];
int dist[1000];
int path[1000];
vector< pair<int,int> > adj[1000];
vector<int> tmp;
set< pair<int,int> > s;

int dij()
{
    for(int i=0;i<1000;i++)
    {
        vis[i]=false;
        dist[i]=99999999;
        path[i]=99999999;
    }
    dist[start]=0;
    path[start]=0;
    s.insert(make_pair(0,start));
    while(!s.empty())
    {
        pair<int,int> u=*s.begin();
        int pos=u.second;
        int dis=u.first;
        vis[pos]=true;
        s.erase(*s.begin());
        if(pos==end) break;
        for(int j=0;j<adj[pos].size();j++)
            if(vis[adj[pos][j].first]==false && dis+adj[pos][j].second<dist[adj[pos][j].first])
            {
                if(dist[adj[pos][j].first]!=99999999) s.erase(make_pair(dist[adj[pos][j].first],adj[pos][j].first));
                dist[adj[pos][j].first]=dis+adj[pos][j].second;
                path[adj[pos][j].first]=pos;
                s.insert(make_pair(dis+adj[pos][j].second,adj[pos][j].first));
            }
    }
    return dist[end];
}

int main()
{
    //freopen("341.INP","r",stdin);
    //freopen("341.OUT","w",stdout);
    while(scanf("%d",&n) && n)
    {
        s.clear();
        tmp.clear();
        for(int i=0;i<1000;i++)
            adj[i].clear();
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&num);
            for(int j=0;j<num;j++)
            {
                scanf("%d%d",&to,&delay);
                adj[i].push_back(make_pair(to,delay));
            }
        }
        scanf("%d%d",&start,&end);
        int result=dij();
        printf("Case %d: Path = ",++tcs);
        int t=end;
        while(t!=start)
        {
            tmp.push_back(t);
            t=path[t];
        }
        printf("%d ",start);
        for(int i=tmp.size()-1;i>=0;i--)
        if(i==0)
            printf("%d",tmp[i]);
        else printf("%d ",tmp[i]);
        printf("; %d second delay\n",result);
        
    }
}
