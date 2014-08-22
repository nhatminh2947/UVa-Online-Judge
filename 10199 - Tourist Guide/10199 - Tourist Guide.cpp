//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10199 - Tourist Guide
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

int n,r,id,child,root;
vi adj[maxN+5];
map<string,int> m;
int ind[105],low[105],parent[105];
bool check[105];
string city[105];

void Point(int u)
{
    low[u] = ind[u] = ++id;
    
    rep(i,sz(adj[u]))
    {
        int v = adj[u][i];
        if(!ind[v])
        {
            if(u == root) child++;
            parent[v] = u;
            Point(v);
            low[u] = min(low[u],low[v]);
            
            if(low[v] >= ind[u])
                check[u] = true;
        }
        else if(parent[u] != v)
            low[u] = min(low[u],ind[v]);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10199 - Tourist Guide.INP","r",stdin);
    freopen("10199 - Tourist Guide.OUT","w",stdout);
    #endif
    
    int tcs = 0;
    while(scanf(" %d ",&n) && n)
    {
        if(tcs) printf("\n");
        m.clear();
        fr(i,1,n)
        {
            parent[i] = i;
            low[i] = ind[i] = 0;
            check[i] = false;
            adj[i].clear();
            cin >> city[i];
            
            m[city[i]] = i;
        }
        
        scanf(" %d ",&r);
        rep(i,r)
        {
            string u,v;
            cin >> u >> v;
            
            int mu = m[u];
            int mv = m[v];
            
            adj[mu].pb(mv);
            adj[mv].pb(mu);
        }
        
        fr(u,1,n)
            if(!ind[u])
            {
                child = 0;
                root = u;
                Point(u);
                
                check[u] = (child > 1);
            }
        
        vector<string> ans;
        fr(u,1,n)
            if(check[u])
                ans.pb(city[u]);
        sort(all(ans));
        
        printf("City map #%d: %d camera(s) found\n",++tcs,sz(ans));
        rep(i,sz(ans)) cout << ans[i] << endl;
    }
    
    return 0;
}
