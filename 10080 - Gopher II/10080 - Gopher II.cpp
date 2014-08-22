//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10080 - Gopher II
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
#define sz(s) (int)s.size()
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
typedef pair<double,double> dd;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<dd> vdd;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 100000

int n,m,s,v;
vdd g, h;
vi adj[1005];
int owner[1005];
bool vis[1005];

double dist(dd u, dd v)
{
    return sqrt((u.ff - v.ff)*(u.ff - v.ff) + (u.ss - v.ss)*(u.ss - v.ss));
}

int solve(int u)
{
    if(vis[u]) return 0;
    
    vis[u] = true;
    
    rep(i,sz(adj[u]))
    {
        int k = adj[u][i];
        
        if(owner[k] == -1 || solve(owner[k]))
        {
            owner[k] = u;
            return 1;
        }
    }
    
    return 0;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10080 - Gopher II.INP","r",stdin);
    freopen("10080 - Gopher II.OUT","w",stdout);
    #endif
    
    while(scanf(" %d %d %d %d ",&n,&m,&s,&v) == 4)
    {
        g.clear();
        h.clear();
        rep(i,n) adj[i].clear();
        
        rep(i,n)
        {
            double x,y;
            scanf("%lf %lf",&x,&y);
            
            g.pb(mp(x,y));
        }
        
        rep(i,m)
        {
            double x,y;
            scanf("%lf %lf",&x,&y);
            
            h.pb(mp(x,y));
        }
        
        rep(i,n)
            rep(j,m)
            {
                double d = dist(g[i],h[j]);
                double t = d / v;
                
                if(t < s)
                    adj[i].pb(j+100);
            }
        
        int cnt = 0;
        rep(i,200) owner[i] = -1;
        
        rep(i,n)
        {
            rep(j,n) vis[j] = false;
            
            cnt += solve(i);
        }
        
        printf("%d\n",n-cnt);
    }
    
    return 0;
}

