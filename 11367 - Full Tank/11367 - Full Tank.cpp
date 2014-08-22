//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11367 - Full Tank
// Verdict: 
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

vii adj[1005];
int n,m;
int p[1005];
int dist[1005][105];

int Dijsktra(int c, int st, int ed)
{
    rep(i,n) rep(j,101) dist[i][j] = INF;
    
    set< pair<int,ii> > s;
    
    s.insert(mp(0,mp(0,st)));
    dist[st][0] = 0;
    
    while(!s.empty())
    {
        pair<int,ii> data = *s.begin();
        
        int u = data.ss.ss;
        int petro = data.ss.ff;
        
        if(u == ed) return dist[u][petro];
        s.erase(data);
        rep(i,sz(adj[u]))
        {
            int v = adj[u][i].ff;
            int w = adj[u][i].ss;
            
            fr(j,w,c)
            {
                if(dist[v][j] > dist[u][petro] + j*p[u])
                {
                    
                    if(dist[v][j] != INF) s.erase(mp(dist[v][j],mp(j,v)));
                    dist[v][j] = dist[u][petro] + j*p[u];
                    s.insert(mp(dist[v][j],mp(j,v)));
                    printf("u = %2d petro = %2d dist[%2d][%2d] = %4d ---> v = %2d j = %2d dist[%2d][%2d] = %4d\n",u,petro,u,petro,dist[u][petro],v,j,v,j,dist[v][j]);
                }
            }
        }
    }
    
    return -1;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11367 - Full Tank.INP","r",stdin);
    freopen("11367 - Full Tank.OUT","w",stdout);
    #endif
    
    while(scanf(" %d %d ",&n,&m) == 2)
    {
        rep(i,n) scanf(" %d ",&p[i]);
        
        rep(i,m)
        {
            int u,v,w;
            scanf(" %d %d %d ",&u,&v,&w);
            
            adj[u].pb(mp(v,w));
            adj[v].pb(mp(u,w));
        }
        
        int tcs;
        scanf(" %d ",&tcs);
        
        fr(t,1,tcs)
        {
            int s,e,c;
            scanf(" %d %d %d ",&c,&s,&e);
            
            int ans = Dijsktra(c,s,e);
            
            if(ans == -1) puts("impossible");
            else printf("%d\n",ans);
        }
    }
    
    return 0;
}
