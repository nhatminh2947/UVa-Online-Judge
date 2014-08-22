//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 10278 - Fire Station
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
int tcs,f,itr;
int ef[510];
int dist[510];
int d[510];
int tmp[510];
bool vis[510];
vector< pair<int,int> > obj[510];
set< pair<int,int> > s;


int dijkstra()
{
    while(!s.empty())
    {
        pair<int,int> temp=*s.begin();
        int dis=temp.first;
        int pos=temp.second;
        vis[pos]=true;
        s.erase(temp);
        for(int i=0;i<obj[pos].size();i++)
            if(vis[obj[pos][i].first]==false && dis+obj[pos][i].second<dist[obj[pos][i].first])
            {
                if(dist[obj[pos][i].first]!=INF) 
                    s.erase(make_pair(dist[obj[pos][i].first],obj[pos][i].first));
                dist[obj[pos][i].first]=dis+obj[pos][i].second;
                s.insert(make_pair(dis+obj[pos][i].second,obj[pos][i].first));
            }
    }
}

int solve(int in)
{
    for(int i=0;i<=itr;i++)
        vis[i]=false;
    s.insert(make_pair(0,in));
    dist[in]=0;
    dijkstra();
}



int main()
{
    freopen("10278.INP","r",stdin);
    freopen("10278.OUT","w",stdout);
    char data[10000];
    scanf("%d",&tcs);
    for(int i=1;i<=tcs;i++)
    {
        s.clear();    
        scanf("%d%d",&f,&itr);
        for(int j=0;j<=itr;j++)
        {
            obj[j].clear();
            dist[j]=INF;
            vis[j]=false;
        }
        for(int j=1;j<=f;j++)
        {
            scanf("%d",&ef[j]);
            s.insert(make_pair(0,ef[j]));
            dist[ef[j]]=0;
        }
        getchar();
        while(gets(data) && data[0]!='\0')
        {
            int tmp1,tmp2,length;
            sscanf(data,"%d %d %d",&tmp1,&tmp2,&length);
            obj[tmp1].push_back(make_pair(tmp2,length));
            obj[tmp2].push_back(make_pair(tmp1,length));
        }
        dijkstra();
        int ans=INF;
        int result=1;
        for(int j=1;j<=itr;j++)
            tmp[j]=dist[j];
        for(int j=1;j<=itr;j++)
        {
            solve(j);
            int maxDist=-INF;
            for(int k=1;k<=itr;k++)
                if(maxDist<dist[k])
                    maxDist=dist[k];
            if(ans>maxDist)
            {
                ans=maxDist;
                result=j;
            }
            for(int j=1;j<=itr;j++)
                dist[j]=tmp[j];
        }  
        printf("%d\n", result);
        if(i!=tcs) printf("\n");
    }
    return 0;
}
