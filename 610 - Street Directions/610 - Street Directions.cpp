//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 610 - Street Directions
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

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define dw(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define sz(s) s.size()
#define read(x) cin >> x
#define read2(x,y) cin >> x >> y
#define read3(x,y,z) cin >> x >> y >> z
#define out(x) cout << x
#define DEBUG(x) cout << #x << " = " << x << endl

#define ull unsigned long long
#define ll long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a)  (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 100000

int n,m,id,root,child;
vi adj[1005];
int low[1005],ind[1005],parent[1005];
bool g[1005][1005];

void reset()
{
    id = 0;
    fr(i,1,n)
    {
        adj[i].clear();
        ind[i] = low[i] = 0;
        parent[i] = i;
        fr(j,1,n) g[i][j] = false;
    }
}

void Point(int u)
{
    low[u] = ind[u] = ++id;
    
    rep(i,sz(adj[u]))
    {
        int v = adj[u][i];
        if(!g[u][v]) continue;
        if(!ind[v])
        {
            if(u == root) child++;
            parent[v] = u;
            Point(v);
            low[u] = min(low[u],low[v]);
            
            if(low[v] <= ind[u])
                g[v][u] = false;
        }
        else if(parent[u] != v)
        {
            g[v][u] = false;
            low[u] = min(low[u],ind[v]);
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("610 - Street Directions.INP","r",stdin);
    freopen("610 - Street Directions.OUT","w",stdout);
    #endif
    int tcs = 1;
    while(scanf(" %d %d ",&n,&m) && n)
    {
        reset();
        printf("%d\n\n",tcs++);
        
        rep(i,m)
        {
            int u,v;
            scanf(" %d %d ",&u,&v);
            g[u][v] = g[v][u] = true;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        
        fr(i,1,n) if(!ind[i])
            Point(i);
        
        fr(i,1,n) fr(j,1,n) if(g[i][j]) printf("%d %d\n",i,j);
        
        puts("#");
    }
    
    return 0;
}
