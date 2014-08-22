//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1112 - Mice and Maze
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

vii adj[maxN+5];
int dist[maxN+5];
int n,e,ti,m;

void dijsktra()
{
    set<ii> s;
    s.insert(mp(0,e));
    dist[e] = 0;
    
    while(!s.empty())
    {
        ii p = *s.begin();
        
        int u = p.ss;
        //DEBUG(u);
        s.erase(p);
        
        rep(i,sz(adj[u]))
        {
            int v = adj[u][i].ff;
            int d = adj[u][i].ss;
            //DEBUG(v);
            //DEBUG(d);
            if(dist[v] > (dist[u] + d) && (dist[u] + d) <= ti)
            {
                if(dist[v] != INF) s.erase(mp(dist[v],v));
                
                dist[v] = dist[u]+d;
                s.insert(mp(dist[v],v));
            }
        }
    }
    
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1112 - Mice and Maze.INP","r",stdin);
    freopen("1112 - Mice and Maze.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    rep(t,tcs)
    {
        if(t) printf("\n");
        scanf(" %d %d %d %d ",&n,&e,&ti,&m);
        
        fr(i,1,n)
        {
            adj[i].clear();
            dist[i] = INF;
        }
        
        rep(i,m)
        {
            int u,v,w;
            scanf(" %d %d %d ",&u,&v,&w);
            
            adj[v].pb(mp(u,w));
        }
        
        dijsktra();
        int ans = 0;
        fr(i,1,n)
        {
            if(dist[i] <= ti)
                ans++;
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
