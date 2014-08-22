//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 11838 - Come and Go
// Verdict: Accepted
//******************************************************************

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

#define pb push_back
#define mp make_pair
#define INF 1000111222
#define maxN 2000

using namespace std;

int n,m,index,ans;
vector<int> adj[maxN+5];
stack<int> s;
int onStack[maxN+5],idx[maxN+5],low[maxN+5];

void init()
{
    for(int i = 1 ; i <= n ; i++)
    {
        adj[i].clear();
        onStack[i] = false;
        idx[i] = low[i] = INF;
    }
    while(!s.empty())
        s.pop();
}

void Tarjan(int u)
{
    idx[u] = low[u] = index++;
    s.push(u);
    onStack[u] = true;
    int sz = adj[u].size();
    int v;
    for(int i = 0 ; i < sz ; i++)
    {
        v = adj[u][i];
        if(idx[v] == INF)
        {
            Tarjan(v);
            low[u] = min(low[u],low[v]);
        }
        else if(onStack[v])
            low[u] = min(low[u],idx[v]);
    }
    if(low[u] == idx[u])
    {
        ans++;
        do
        {
            v = s.top();
            onStack[v] = false;
            s.pop();
        }while(u != v);
    }
}

int main()
{
    freopen("11838 - Come and Go.INP","r",stdin);
    freopen("11838 - Come and Go.OUT","w",stdout);
    
    while(scanf(" %d %d ",&n,&m) && n)
    {
        init();
        for(int i = 0 ; i < m ; i++)
        {
            int u,v,stt;
            scanf(" %d %d %d ",&u,&v,&stt);
            adj[u].pb(v);
            if(stt == 2)
                adj[v].pb(u);
        }
        index = 1;
        ans = 0;
        for(int i = 1 ; i <= n && ans <= 1; i++)
            if(idx[i] == INF)
                Tarjan(i);
        
        if(ans == 1)
            printf("1\n");
        else printf("0\n");
    }
    
    return 0;
}
