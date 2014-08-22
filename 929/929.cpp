//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 929 - Number Maze
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

int n,N,M;
int maze[1000+5][1000+5];
int dist[1000+5][1000+5];
bool vis[1000+5][1000+5];
set< pair<int,pair<int,int> > > s;

int init()
{
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            vis[i][j]=false;
            dist[i][j]=INF;
        }
}

int dijkstra()
{
    int dx[]={-1, 1, 0, 0};
    int dy[]={ 0, 0,-1, 1};
    s.clear();
    dist[0][0]=maze[0][0];
    s.insert(make_pair(dist[0][0],make_pair(0,0)));
    vis[0][0]=true;
    while(!s.empty())
    {
        pair< int,pair<int,int> > tmp=*s.begin();
        int dis=tmp.first;
        int y=tmp.second.first;
        int x=tmp.second.second;
        if(x==(M-1) && y==(N-1)) break;
        s.erase(tmp);
        for(int i=0;i<4;i++)
        {
            if(vis[y+dy[i]][x+dx[i]]==false && 0<=y+dy[i] && y+dy[i]<N && 0<=x+dx[i] && x+dx[i]<M && dis+maze[y+dy[i]][x+dx[i]]<dist[y+dy[i]][x+dx[i]])
            {
                if(dist[y+dy[i]][x+dx[i]]!=INF) s.erase(make_pair(dist[y+dy[i]][x+dx[i]],make_pair(y+dy[i],x+dx[i])));
                dist[y+dy[i]][x+dx[i]]=dis+maze[y+dy[i]][x+dx[i]];
                s.insert(make_pair(dist[y+dy[i]][x+dx[i]],make_pair(y+dy[i],x+dx[i])));
            }
        }
    }
    return dist[N-1][M-1];
}

int main()
{
    //freopen("929.INP","r",stdin);
    //freopen("929.OUT","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&N,&M);
        init();
        for(int j=0;j<N;j++)
            for(int k=0;k<M;k++)
                scanf("%d",&maze[j][k]);
        printf("%d\n",dijkstra());
    }
    return 0;
}
