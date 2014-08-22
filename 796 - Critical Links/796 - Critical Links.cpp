//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 796 - Critical Links
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
#define maxN 100

vi adj[maxN+5];
vii p;
int low[maxN+5],ind[maxN+5],parent[maxN+5];
int id,n;

void Bridge(int u)
{
    low[u] = ind[u] = ++id;
    
    rep(i,sz(adj[u]))
    {
        int v = adj[u][i];
        if(!ind[v])
        {
            parent[v] = u;
            Bridge(v);
            
            if(low[v] > ind[u])
            {
                int uu = min(u,v);
                int vv = max(u,v);
                p.pb(mp(uu,vv));
            }
            low[u] = min(low[u],low[v]);
        }
        else if(parent[u] != v)
            low[u] = min(ind[v],low[u]);
    }
}

void reset()
{
    id = 0;
    p.clear();
    rep(i,n)
    {
        adj[i].clear();
        low[i] = ind[i] = 0;
        parent[i] = i;
    }
}

bool cmp(ii u, ii v)
{
    if(u.ff == v.ff) return u.ss < v.ss;
    return u.ff < v.ff;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("796 - Critical Links.INP","r",stdin);
    freopen("796 - Critical Links.OUT","w",stdout);
    #endif
    
    while(scanf(" %d ",&n) == 1)
    {
        reset();
        rep(i,n)
        {
            int u,m;
            scanf(" %d ",&u);
            scanf(" (%d) ",&m);
            rep(i,m)
            {
                int v;
                scanf(" %d ",&v);
                
                adj[u].pb(v);
                adj[v].pb(u);
            }
        }
        
        rep(i,n) if(!ind[i]) Bridge(i);
        sort(all(p),cmp);
        printf("%d critical links\n",sz(p));
        rep(i,sz(p))
            printf("%d - %d\n",p[i].ff,p[i].ss);
        printf("\n");
    }
    
    return 0;
}
