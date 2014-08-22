//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 11504 - Dominos - DFS
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
#define i64 long long
#define u64 unsigned long long
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define maxN 100000
#define INF 1000111222

using namespace std;

bool vis[maxN+5];
int n,m;
vector<int> adj[maxN+5];

void DFS(int u)
{
    if(vis[u])
        return;
    vis[u] = true;
    int sz = adj[u].size();
    for(int i = 0 ; i < sz ; i++)
    {
        int v = adj[u][i];
        if(!vis[v])
            DFS(v);
    }
}

int main()
{
	freopen("11504 - Dominos.INP","r",stdin);
	freopen("11504 - Dominos.OUT","w",stdout);
	
	int tcs;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
	    scanf(" %d %d ",&n,&m);
	    for(int i = 1 ; i <= n ; i++)
	    {
	        adj[i].clear();
            vis[i] = false;
	    }
            
        for(int i = 0 ; i < m ; i++)
        {
            int u,v;
            scanf(" %d %d ",&u,&v);
            adj[u].pb(v);
        }
        
        vector<int> v;
        for(int i = 1 ; i <= n ; i++)
            if(!vis[i])
            {
                DFS(i);
                v.pb(i);
            }
        
        for(int i = 1 ; i <= n ; i++)
            vis[i] = false;
        
        int cnt = 0;
        for(int i = v.size()-1 ; i >= 0 ; i--)
        {
            if(!vis[v[i]])
            {
                DFS(v[i]);
                cnt++;
            }
        }
        printf("%d\n",cnt);
	}

	return 0;
}

