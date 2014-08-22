//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10000 - Longest Paths
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

int n;
vi adj[105];
int dist[105],longest[105];

int DFS(int u)
{
    if(dist[u] != INF) return dist[u];
    
    int ans = 0;
    rep(i,sz(adj[u]))
    {
        int v = adj[u][i];
        int d = DFS(v) + 1;
        if(ans < d || (ans == d && longest[u] > longest[v]))
        {
            ans = d;
            longest[u] = longest[v];
        }
    }
    
    return dist[u] = ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10000 - Longest Paths.INP","r",stdin);
    freopen("10000 - Longest Paths.OUT","w",stdout);
    #endif
    int tcs = 1;
    while(scanf(" %d ",&n) && n)
    {
        int st;
        scanf(" %d ",&st);
        //DEBUG(n);
        fr(i,1,n)
        {
            longest[i] = i;
            dist[i] = INF;
            adj[i].clear();
        }
        
        int u,v;
        while(scanf(" %d %d ",&u,&v) && u)
            adj[u].pb(v);
        
        DFS(st);
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",tcs++,st,dist[st],longest[st]);
    }
    
    return 0;
}
