//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 12047 - Highest Paid Toll
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
#define maxN 10000

vii ori[maxN+5],rev[maxN+5];
int distStart[maxN+5],distEnd[maxN+5];
int m,n,st,ed;
ll p;

void dijkstra_Start()
{
    fr(i,1,n) distStart[i] = INF;
    set<ii> s;
    
    s.insert(mp(0,st));
    distStart[st] = 0;
    
    while(!s.empty())
    {
        ii p = *s.begin();
        
        int d = p.ff;
        int u = p.ss;
        s.erase(p);
        
        rep(i,sz(ori[u]))
        {
            int v = ori[u][i].ff;
            int dd = ori[u][i].ss;
            
            if(distStart[v] > dd + d)
            {
                if(distStart[v] != INF) s.erase(mp(distStart[v],v));
                distStart[v] = dd + d;
                s.insert(mp(distStart[v],v));
            }
        }
    }
}

void dijkstra_End()
{
    fr(i,1,n) distEnd[i] = INF;
    set<ii> s;
    
    s.insert(mp(0,ed));
    distEnd[ed] = 0;
    
    while(!s.empty())
    {
        ii p = *s.begin();
        
        int d = p.ff;
        int u = p.ss;
        s.erase(p);
        
        rep(i,sz(rev[u]))
        {
            int v = rev[u][i].ff;
            int dd = rev[u][i].ss;
            
            if(distEnd[v] > dd + d)
            {
                if(distEnd[v] != INF) s.erase(mp(distEnd[v],v));
                distEnd[v] = dd + d;
                s.insert(mp(distEnd[v],v));
            }
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("12047 - Highest Paid Toll.INP","r",stdin);
    freopen("12047 - Highest Paid Toll.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    
    rep(t,tcs)
    {
        scanf(" %d %d %d %d %lld ",&n,&m,&st,&ed,&p);
        
        fr(i,1,n)
        {
            ori[i].clear();
            rev[i].clear();
        }
        
        rep(i,m)
        {
            int u,v,w;
            scanf(" %d %d %d ",&u,&v,&w);
            
            ori[u].pb(mp(v,w));
            rev[v].pb(mp(u,w));
        }
        
        int ans = -1;
        dijkstra_Start();
        dijkstra_End();
        
        fr(u,1,n)
        {   
            rep(i,sz(ori[u]))
            {
                int v = ori[u][i].ff;
                int w = ori[u][i].ss;
                
                ll C = distStart[u] + w + distEnd[v];
                if(C <= p)
                    ans = max(ans,w);
            }
        }
        
        printf("%d\n",ans);
    }

    return 0;
}