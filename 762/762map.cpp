//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Number: 762 - We Ship Cheap
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

map< string, string > route;
map< string, bool > vis;
map< string, vector< string > > data;
string s,e;
int n;

void init()
{
    route.clear();
    vis.clear();
    data.clear();
}

bool BFS()
{
    queue< string > q;
    q.push(e);
    while(!q.empty())
    {
        string pos=q.front();
        q.pop();
        if(pos==s) return true;
        
        int sz=data[pos].size();
        for(int i=0;i<sz;i++)
        {
            string p=data[pos][i];
            if(!vis[p])
            {
                route[p]=pos;
                vis[p]=true;
                q.push(p);
            }
        }
    }
    return false;
}

int main()
{
    //freopen("762.INP","r",stdin);
    //freopen("762.OUT","w",stdout);
    bool line=false;
    while(scanf(" %d ",&n)==1)
    {
        if(line) printf("\n");
        line=true;
        init();
        for(int i=0;i<n;i++)
        {
            cin>>s>>e;
            vis[s]=vis[e]=false;
            data[s].push_back(e);
            data[e].push_back(s);
        }
        cin>>s>>e;
        if(s==e) cout<<e<<" "<<s<<endl;
        else
        {
            bool t=BFS();
            if(t)
            {
                string tmp=s;
                while(tmp!=e)
                {
                    cout<<tmp<<" "<<route[tmp]<<endl;
                    tmp=route[tmp];
                }
            }
            else printf("No route\n");
        }
    }
    return 0;
}
