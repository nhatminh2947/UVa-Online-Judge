//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Number: 567 - Risk
// Verdict: Accepted
//******************************************************************
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
#define PI 3,1415926535

using namespace std;

vector<int> ct[25];
bool vis[25];
int dist[25];
int n,test;

void init()
{
    for(int i=0;i<25;i++)
    {
        ct[i].clear();
        vis[i]=false;
        dist[i]=INF;
    }
}

int BFS(int s,int e)
{
    for(int i=0;i<25;i++)
    {
        vis[i]=false;
        dist[i]=INF;
    }
    
    queue< pair<int,int> > q;
    vis[s]=true;
    dist[s]=0;
    q.push(make_pair(s,0));
    while(!q.empty())
    {
        int pos=q.front().first;
        int dis=q.front().second;
        q.pop();
        vis[pos]=true;
        
        if(pos==e) return dist[pos];
        
        int sz=ct[pos].size();
        for(int i=0;i<sz;i++)
        {
            int p=ct[pos][i];
            if(!vis[p] && dist[p]>dis+1)
            {
                dist[p]=dis+1;
                q.push(make_pair(p,dist[p]));
            }
        }
    }
}

void input()
{
    int tmp;
    for(int i=0;i<n;i++)
    {
        scanf(" %d ",&tmp);
        ct[1].push_back(tmp);
        ct[tmp].push_back(1);
    }
    for(int i=2;i<=19;i++)
    {
        scanf(" %d ",&n);
        for(int j=0;j<n;j++)
        {
            scanf(" %d ",&tmp);
            ct[i].push_back(tmp);
            ct[tmp].push_back(i);
        }
    }
}

void output()
{
    int tcs,s,e;
    scanf(" %d ",&tcs);
    
    printf("Test Set #%d\n",++test);
    
    for(int i=0;i<tcs;i++)
    {
        scanf(" %d %d ",&s,&e);
        printf("%2d to %2d: %d\n",s,e,BFS(s,e));
    }
    
    printf("\n");
}

int main()
{
    //freopen("567.INP","r",stdin);
    //freopen("567.OUT","w",stdout);
    test=0;
    while(scanf(" %d ",&n)==1)
    {
        init();
        input();
        output();
    }
    return 0;
}
