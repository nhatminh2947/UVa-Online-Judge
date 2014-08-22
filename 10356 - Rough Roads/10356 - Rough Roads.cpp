//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10356 - Rough Roads
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

int n,r;
vii adj[505];
int dist[5][505];

int Dijsktra()
{
    set< pair<int,ii> > s;
    s.insert(mp(0,mp(1,0)));
    dist[1][0] = 0;
    
    while(!s.empty())
    {
        pair<int,ii> p = *s.begin();
        int u = p.ss.ss;
        int stt = p.ss.ff;
        
        if(u == n-1 && stt == 1) return dist[stt][u];
        
        s.erase(p);
        
        rep(i,sz(adj[u]))
        {
            int v = adj[u][i].ff;
            int d = adj[u][i].ss;
            
            if(dist[1-stt][v] > dist[stt][u] + d)
            {
                if(dist[1-stt][v] != INF) s.erase(mp(dist[1-stt][v],mp(1-stt,v)));
                dist[1-stt][v] = dist[stt][u] + d;
                s.insert(mp(dist[1-stt][v],mp(1-stt,v)));
            }
        }
    }
    
    return -1;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10356 - Rough Roads.INP","r",stdin);
    freopen("10356 - Rough Roads.OUT","w",stdout);
    #endif
    int tcs = 1;
    while(scanf(" %d %d ",&n,&r) == 2)
    {
        rep(i,n)
        {
            adj[i].clear();
            dist[0][i] = dist[1][i] = INF;
        }
        int u,v,w;
        rep(i,r)
        {
            scanf(" %d %d %d ",&u,&v,&w);
            adj[u].pb(mp(v,w));
            adj[v].pb(mp(u,w));
        }
        
        printf("Set #%d\n",tcs++);
        
        int ans = Dijsktra();
        if(ans == -1) puts("?");
        else printf("%d\n",ans);
    }
    
    return 0;
}
