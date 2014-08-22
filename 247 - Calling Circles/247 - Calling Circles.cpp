//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 247 - Calling Circles
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
#define maxN 25
#define INF 1000111222

using namespace std;

int n,m,id;
map<string,int> enc;
vector<int> adj[maxN+5];
stack<int> s;
string str[maxN+5];
int ind[maxN+5],low[maxN+5];
bool onStack[maxN+5];

inline void init()
{
    id = 0;
    enc.clear();
    while(!s.empty())
        s.pop();
    for(int i = 1 ; i <= n ; i++)
    {
        adj[i].clear();
        ind[i] = low[i] = INF;
        onStack[i] = false;
    }
}

inline void Tarjan(int u)
{
    ind[u] = low[u] = id++;
    onStack[u] = true;
    s.push(u);
    int v;
    int sz = adj[u].size();
    for(int i = 0 ; i < sz ; i++)
    {
        v = adj[u][i];
        if(ind[v] == INF)
        {
            Tarjan(v);
            low[u] = min(low[u],low[v]);
        }
        else if(onStack[v])
            low[u] = min(low[u],ind[v]);
    }
    
    if(low[u] == ind[u])
    {
        bool comma = false;
        do
        {
            if(comma)
                printf(", ");
            else comma = true;
            v = s.top();
            s.pop();
            onStack[v] = false;
            cout << str[v];
        }while(u != v);
        printf("\n");
    }
}

int main()
{
	freopen("247 - Calling Circles.INP","r",stdin);
	freopen("247 - Calling Circles.OUT","w",stdout);
	int tcs = 0;
	while(scanf(" %d %d ",&n,&m) && (n || m))
	{
	    init();
	    int cnt = 0;
	    for(int i = 0 ; i < m ; i++)
	    {
	        string u,v;
	        cin >> u >> v;
	        if(!enc[u])
	        {
                enc[u] = ++cnt;
                str[cnt] = u;
	        }
            if(!enc[v])
            {
                enc[v] = ++cnt;
                str[cnt] = v;
            }
            
            adj[enc[u]].pb(enc[v]);
	    }
	    if(tcs)
            printf("\n");
        printf("Calling circles for data set %d:\n",++tcs);
	    for(int i = 1 ; i <= n ; i++)
            if(ind[i] == INF)
                Tarjan(i);
        
	}

	return 0;
}

