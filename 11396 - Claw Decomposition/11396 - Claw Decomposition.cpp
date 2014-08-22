//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11396 - Claw Decomposition
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

bool vis[305],color[305];
vi adj[305];
int n;

void reset()
{
    fr(i,1,n)
    {
        adj[i].clear();
        vis[i] = color[i] = false;
    }
}

bool isBipartile(int st)
{
    queue<int> q;
    q.push(st);
    vis[st] = true;
    
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        
        rep(i,sz(adj[u]))
        {
            int v = adj[u][i];
            
            if(!vis[v])
            {
                vis[v] = true;
                color[v] = !color[u];
                q.push(v);
            }
            else if(color[u] == color[v]) return false;
        }
    }
    
    return true;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11396 - Claw Decomposition.INP","r",stdin);
    freopen("11396 - Claw Decomposition.OUT","w",stdout);
    #endif
    
    while(scanf(" %d ",&n) &&n)
    {
        reset();
        int u,v;
        while(scanf(" %d %d ",&u,&v) && u)
        {
            adj[u].pb(v);
            adj[v].pb(u);
        }
        
        if(isBipartile(1)) puts("YES");
        else puts("NO");
    }
    
    return 0;
}
