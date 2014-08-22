//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10765 - Doves and bombs
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

vi adj[maxN+5];
vii ans;
bool vis[maxN+5],check[maxN+5];
int low[maxN+5],ind[maxN+5],parent[maxN+5],cnt[maxN+5];
int id,n,m;

void reset()
{
    id = 0;
    ans.clear();
    rep(i,n)
    {
        adj[i].clear();
        check[i] = false;
        low[i] = ind[i] = cnt[i] = 0;
        parent[i] = i;
    }
}

void Point(int u)
{
    low[u] = ind[u] = ++id;
    int child = 0;
    rep(i,sz(adj[u]))
    {
        int v = adj[u][i];
        if(!ind[v])
        {
            parent[v] = u;
            child++;
            Point(v);
            
            if(low[v] >= ind[u])
            {
                check[u] = true;
                cnt[u]++;
            }
            low[u] = min(low[u],low[v]);
        }
        else if(parent[u] != v) low[u] = min(low[u],ind[v]);
    }
    
    if(parent[u] == u && child == 1) cnt[u] = 0;
}

bool cmp(ii u, ii v)
{
    if(u.ss == v.ss) return u.ff < v.ff;
    return u.ss > v.ss;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10765 - Doves and bombs.INP","r",stdin);
    freopen("10765 - Doves and bombs.OUT","w",stdout);
    #endif
    
    while(scanf(" %d %d ",&n,&m) && n)
    {
        reset();
        int a,b;
        while(scanf(" %d %d ",&a,&b) && a != -1)
        {
            adj[a].pb(b);
            adj[b].pb(a);
        }
        
        Point(0);
        
        rep(u,n) ans.pb(mp(u,cnt[u]+1));
        
        sort(all(ans),cmp);
        
        rep(i,m) printf("%d %d\n",ans[i].ff,ans[i].ss);
        
        printf("\n");
    }
    
    return 0;
}
