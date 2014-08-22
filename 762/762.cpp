//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Number: 762 - We Ship Cheap
// Verdict:
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

map<string,int> m;
map<int,string> trace;
vector<int> data[10005];
bool vis[10005];
int path[10005],dist[10005];
char s[55],e[55];
int n,line=0;


void init()
{
    m.clear();
    for(int i=0;i<5005;i++)
    {
        data[i].clear();
        path[i]=dist[i]=INF;
    }
}

bool BFS()
{
    queue< pair<int,int> > q;
    dist[m[s]]=0;
    path[m[s]]=m[s];
    vis[m[s]]=true;
    q.push(make_pair(m[s],0));
    while(!q.empty())
    {
        int pos=q.front().first;
        int dis=q.front().second;
        vis[pos]=true;
        q.pop();
        
        if(pos==m[e]) return true;
        
        int sz=data[pos].size();
        for(int i=0;i<sz;i++)
        {
            int p=data[pos][i];
            if(!vis[p] && dist[p]>dis+1)
            {
                dist[p]=dis+1;
                path[pos]=p;
                q.push(make_pair(p,dist[p]));
            }
        }
    }
    return false;
}

void input()
{
    int cnt=1;
    for(int i=0;i<n;i++)
    {
        scanf(" %s %s ",&s,&e);
        if(!m[s])
        {
            trace[cnt]=s;
            m[s]=cnt++;
        }
        if(!m[e])
        {
            trace[cnt]=e;
            m[e]=cnt++;
        }
        
        int a=m[s];
        int b=m[e];
        
        data[a].push_back(b);
        data[b].push_back(a);
    }
    scanf(" %s %s ",&s,&e);
}

void output()
{
    if(line++) printf("\n");
    if(!strcmp(s,e))
        printf("%s %s",s,e);
    else if(BFS())
    {
        int tmp=m[s];
        while(tmp!=m[e])
        {
            cout<<trace[tmp]<<" "<<trace[path[tmp]]<<endl;
            tmp=path[m[trace[tmp]]];
        }
    }
    else printf("No route\n");
}

int main()
{
    freopen("762.INP","r",stdin);
    freopen("762.OUT","w",stdout);
    while(scanf(" %d ",&n)==1)
    {
        init();
        input();
        output();
    }
    return 0;
}
