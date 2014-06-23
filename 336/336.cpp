//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 336 - A Node Too Far
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

int nc,node1,node2,start,ttl;
int dist[1000+5];
bool vis[1000+5];
vector<int> obj[1000+5];
map<int,bool> check;
map<int,bool>::iterator it;

int bfs()
{
    int count=0;
    it=check.begin();
    while(it!=check.end())
    {
        vis[(*it).first]=false;
        dist[(*it).first]=INF;
        it++;
    }
    queue<int> q;
    q.push(start);
    vis[start]=true;
    dist[start]=0;
    while(!q.empty())
    {
        int tmp=q.front();
        if(dist[tmp]>ttl) break;
        count++;
        q.pop();
        for(int i=0;i<obj[tmp].size();i++)
            if(vis[obj[tmp][i]]==false)
            {
                q.push(obj[tmp][i]);
                dist[obj[tmp][i]]=dist[tmp]+1;
                vis[obj[tmp][i]]=true;
            }
    }
    return count;
}

int main()
{
    //freopen("336.INP","r",stdin);
    //freopen("336.OUT","w",stdout);
    int tcs=0;
    while(scanf("%d",&nc) && nc)
    {
        for(int i=0;i<=1000;i++)
            obj[i].clear();
        check.clear();
        for(int i=0;i<nc;i++)
        {
            scanf("%d%d",&node1,&node2);
            obj[node1].push_back(node2);
            obj[node2].push_back(node1);
            check[node1]=true;
            check[node2]=true;
        }
        while(scanf("%d%d",&start,&ttl))
        {
            if(start==0 && ttl==0) break;
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++tcs,check.size()-bfs(),start,ttl);
        }
    }
    return 0;
}
