//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 11709 - Trust groups
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
#define maxN 1000
#define INF 1000111222

using namespace std;

map<string,int> m;
vector<int> adj[maxN+5];
stack<int> s;
int low[maxN+5],ind[maxN+5];
bool onStack[maxN+5];
int p,t,scc,id;

inline void init()
{
    scc = id = 0;
    m.clear();
    while(!s.empty())
        s.pop();
    for(int i = 1 ; i <= p ; i++)
    {
        adj[i].clear();
        low[i] = ind[i] = INF;
        onStack[i] = false;
    }
}

inline void Tarjan(int u)
{
    low[u] = ind[u] = id++;
    s.push(u);
    onStack[u] = true;
    int sz = adj[u].size();
    int v;
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
        //printf("SCC:");
        scc++;
        do
        {
            v = s.top();
            s.pop();
            onStack[v] = false;
            //printf(" %d",v);
        }while(u != v);
        //printf("\n");
    }
}

int main()
{
	freopen("11709 - Trust groups.INP","r",stdin);
	freopen("11709 - Trust groups.OUT","w",stdout);
	
	while(scanf(" %d %d ",&p,&t) && p)
	{
	    init();
	    for(int i = 1 ; i <= p ; i++)
	    {
            string str;
            getline(cin,str);
            m[str] = i;
	    }
	    
	    for(int i = 0 ; i < t ; i++)
	    {
	        string s1,s2;
	        getline(cin,s1);
	        getline(cin,s2);
	        adj[m[s1]].pb(m[s2]);
	    }
	    
	    for(int i = 1 ; i <= p ; i++)
            if(ind[i] == INF)
                Tarjan(i);
        
        printf("%d\n",scc);
	}

	return 0;
}

