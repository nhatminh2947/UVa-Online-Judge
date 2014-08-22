//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 753 - A Plug for UNIX
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
#include <cctype>
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define maxN 550
#define INF 1000111222

using namespace std;

const int st = 0, ed = 500;

map<string,int> si;
vector<int> adj[maxN];
int n,m,k;
int f[maxN][maxN], c[maxN][maxN];
int trace[maxN], cnt[maxN];

inline void init()
{
    si.clear();
    for(int i = 0 ; i <= ed ; i++)
    {
        adj[i].clear();
        cnt[i] = 0;
        for(int j = 0 ; j <= ed ; j++)
            f[i][j] = c[i][j] = 0;
    }
}

inline bool BFS()
{
    for(int i = 0 ; i <= ed ; i++)
        trace[i] = 0;
    
    queue<int> q;
    q.push(st);
    trace[st] = st;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        
        int sz = adj[u].size();
        for(int i = 0 ; i < sz ; i++)
        {
            int v = adj[u][i];
            if(!trace[v] && f[u][v] < c[u][v])
            {
                trace[v] = u;
                if(v == ed)
                    return true;
                q.push(v);
            }
        }
    }
    
    return false;
}

inline void IncFlow()
{
    int v = ed;
    int d = INF;
    while(st != v)
    {
        int u = trace[v];
        d = min(d, c[u][v] - f[u][v]);
        v = u;
    }
    
    v = ed;
    while(st != v)
    {
        int u = trace[v];
        f[u][v] += d;
        f[v][u] -= d;
        v = u;
    }
}

int main()
{
    freopen("753 - A Plug for UNIX.INP","r",stdin);
    freopen("753 - A Plug for UNIX.OUT","w",stdout);
    int tcs;
    scanf(" %d ",&tcs);
    for(int t = 0 ; t < tcs ; t++)
    {
        if(t) printf("\n");
        init();
        int am = 0;
        scanf(" %d ",&n);
        for(int i = 0 ; i < n ; i++)
        {
            string str;
            cin >> str;
            if(!si[str])
                si[str] = ++am;
            int cs = si[str];
            
            if(c[cs][ed] == 0)
            {
                adj[cs].pb(ed);
                adj[ed].pb(cs);
            }
            c[cs][ed]++;
        }
        int m;
        scanf(" %d ",&m);
        for(int i = 0 ; i < m ; i++)
        {
            string s1, s2;
            cin >> s1 >> s2;
            if(!si[s1])
                si[s1] = ++am;
            if(!si[s2])
                si[s2] = ++am;
            
            int cs1 = si[s1];
            int cs2 = si[s2];
            adj[st].pb(cs1);
            adj[cs1].pb(st);
            c[st][cs1] = 1;
            
            adj[cs1].pb(cs2);
            adj[cs2].pb(cs1);
            c[cs1][cs2] = 1;
        }
        
        scanf(" %d ",&k);
        for(int i = 0 ; i < k ; i++)
        {
            string s1,s2;
            cin >> s1 >> s2;
            if(!si[s1])
                si[s1] = ++am;
            if(!si[s2])
                si[s2] = ++am;
            
            int cs1 = si[s1];
            int cs2 = si[s2];
            
            c[cs1][cs2] = INF;
            adj[cs1].pb(cs2);
            adj[cs2].pb(cs1);
        }
        
        while(BFS())
            IncFlow();
        
        int sum = 0;
        int sz = adj[st].size();
        for(int i = 0 ; i < sz ; i++)
        {
            int v = adj[st][i];
            sum += f[st][v];
        }
        
        printf("%d\n",m-sum);
    }
    return 0;
}
