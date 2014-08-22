//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11492 - Babel
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
#define maxN 4000

vector< pair<int,string> > adj[maxN+5];
int dist[maxN+5][305];
map<string,int> m;
int n;

int dijsktra(int st, int ed)
{
    set< pair<int,pair<int,char> > > s;
    
    s.insert(mp(0,mp(st,0)));
    dist[st][0] = 0;
    
    while(!s.empty())
    {
        pair<int,pair<int,char> > p = *s.begin();
        
        int du = p.ff;
        int u = p.ss.ff;
        char c = p.ss.ss;
        
        if(u == ed) return dist[u][c];
        
        s.erase(p);
        
        rep(i,sz(adj[u]))
        {
            int v = adj[u][i].ff;
            string d = adj[u][i].ss;
            
            if(c != d[0] && dist[u][c] + sz(d) < dist[v][d[0]])
            {
                if(dist[v][d[0]] != INF) s.erase(mp(dist[v][d[0]],mp(v,d[0])));
                dist[v][d[0]] = dist[u][c] + sz(d);
                s.insert(mp(dist[v][d[0]],mp(v,d[0])));
            }
        }
    }
    
    return -1;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11492 - Babel.INP","r",stdin);
    freopen("11492 - Babel.OUT","w",stdout);
    #endif
    
    fr(i,1,4000) adj[i].clear();
    while(scanf(" %d ",&n) && n)
    {
        int cnt = 0;
        m.clear();
        string st,ed;
        read2(st,ed);
        
        rep(i,n)
        {
            string u,v,w;
            read3(u,v,w);
            
            int mu,mv;
            
            if(!m[u]) m[u] = ++cnt;
            if(!m[v]) m[v] = ++cnt;
            
            mu = m[u];
            mv = m[v];
            
            adj[mu].pb(mp(mv,w));
            adj[mv].pb(mp(mu,w));
        }
        
        if(!m[st] && !m[ed])
        {
            puts("impossivel");
            continue;
        }
        
        fr(i,1,cnt)
        {
            dist[i][' '] = INF;
            fr(j,'a','z')
                dist[i][j] = INF;
        }
        
        int ans = dijsktra(m[st],m[ed]);
        
        if(ans == -1) puts("impossivel");
        else printf("%d\n",ans);
        
        fr(i,1,cnt) adj[i].clear();
    }
    
    return 0;
}
