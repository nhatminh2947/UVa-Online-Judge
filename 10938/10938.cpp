//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10938 - Flea circus
// Verdict: Accepted
//******************************************************************
#include <iostream>
#include <iomanip>
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
#define INF 1000000000
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)

using namespace std;

int n,f1,f2;
bool vis[5005];
int path[5005];
vector<int> data[5005];

int BFS()
{
    for(int i=1;i<=n;i++)
        vis[i]=false;
    
    queue< pair<int,int> > q;
    q.push(make_pair(f1,1));
    vis[f1]=true;
    
    while(!q.empty())
    {
        int pos=q.front().first;
        int dis=q.front().second;
        
        if(pos==f2)
            return dis;
        q.pop();
        
        int sz=data[pos].size();
        for(int i=0;i<sz;i++)
        {
            if(!vis[data[pos][i]])
            {
                q.push(make_pair(data[pos][i],dis+1));
                vis[data[pos][i]]=true;
                path[data[pos][i]]=pos;
            }
        }
    }
}

int main()
{
    freopen("10938.INP","r",stdin);
    freopen("10938.OUT","w",stdout);
    while(scanf(" %d ",&n) && n)
    {
        for(int i=0;i<=n;i++)
            data[i].clear();
        for(int i=1;i<=n-1;i++)
        {
            int u,v;
            scanf(" %d %d ",&u,&v);
            data[u].push_back(v);
            data[v].push_back(u);
        }
        int q;
        scanf(" %d ",&q);
        for(int i=0;i<q;i++)
        {
            scanf(" %d %d ",&f1,&f2);
            int res=BFS();
            bool meet=false;
            if(res%2)
            {
                res=res/2+1;
                meet=true;
            }
            else res/=2;
            
            int k=1;
            int p=f2;
            while(k<res)
            {
                p=path[p];
                k++;
            }
            if(meet)
                printf("The fleas meet at %d.\n",p);
            else
            {
                int q=path[p];
                if(p>q) swap(p,q);
                printf("The fleas jump forever between %d and %d.\n",p,q);
            }
        }
    }
    return 0;
}
