//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 383 - Shipping Routes
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

int tcs,N,M,P;
int dist[30+5];
bool vis[30+5];
map<string,int> code;
vector<int> data[30+5];

int bfs(string start,string end)
{
    bool lock=false;
    int res=INF;
    for(int i=0;i<=M;i++)
    {
        dist[i]=INF;
        vis[i]=false;
    }
    queue<int> q;
    dist[code[start]]=0;
    q.push(code[start]);
    while(!q.empty())
    {
        int tmp=q.front();
        q.pop();
        vis[tmp]=true;
        for(int i=0;i<data[tmp].size();i++)
            if(vis[data[tmp][i]]==false)
            {
                vis[data[tmp][i]]=true;
                dist[data[tmp][i]]=dist[tmp]+1;
                if(data[tmp][i]==code[end]) 
                {
                    res=dist[data[tmp][i]];
                    lock=true;
                    break;
                }
                q.push(data[tmp][i]);
            }
        if(lock) break;
    }
    return res;
}

int main()
{
    //freopen("383.INP","r",stdin);
    //freopen("383.OUT","w",stdout);
    string cm,data1,data2,start,end;
    int cost;
    scanf(" %d ",&tcs);
    printf("SHIPPING ROUTES OUTPUT\n");
    for(int i=1;i<=tcs;i++)
    {
        int encode=0;
        code.clear();
        scanf(" %d %d %d ",&M,&N,&P);
        for(int j=0;j<=M;j++)
            data[j].clear();
        for(int j=0;j<M;j++)
        {
            cin>>cm;
            code[cm]=encode++;
        }
        for(int j=0;j<N;j++)
        {
            cin>>data1>>data2;
            data[code[data1]].push_back(code[data2]);
            data[code[data2]].push_back(code[data1]);
        }
        printf("\nDATA SET  %d\n\n",i);
        for(int j=0;j<P;j++)
        {
            cin>>cost>>start>>end;
            int res=bfs(start,end);
            if(res==INF) printf("NO SHIPMENT POSSIBLE\n");
            else printf("$%d\n",cost*res*100);
        }
    }
    printf("\nEND OF OUTPUT\n");
    return 0;
}
