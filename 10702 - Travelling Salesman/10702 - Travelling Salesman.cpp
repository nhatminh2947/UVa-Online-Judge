//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10702 - Travelling Salesman
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
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 100000

int c,st,e,t;
vii adj[105];
int ed[105];
int pr[105][1005];

int BFS()
{
    
    queue<ii> q;
    q.push(mp(st,0));
    pr[st][0] = 0;
    int ans = -1;
    while(!q.empty())
    {
        int u = q.front().ff;
        int d = q.front().ss;
        
        if(ed[u] && d == t)
            ans = max(ans,pr[u][d]);
        
        q.pop();
        
        rep(i,sz(adj[u]))
        {
            int v = adj[u][i].ff;
            int w = adj[u][i].ss + pr[u][d];
            
            if(d+1 <= t && pr[v][d+1] < w)
            {
                pr[v][d+1] = w;
                q.push(mp(v,d+1));
            }
        }
    }
    
    return ans;
}

int DFS(int u, int d)
{
    if(pr[u][d] != -1) return pr[u][d];
    
    if(ed[u] && d == t) return 0;
    
    int ans = -INF;
    rep(i,sz(adj[u]))
    {
        int v = adj[u][i].ff;
        int w = adj[u][i].ss;
        //printf("u = %d d = %d ---> v = %d\n",u,d,v);
        if(d+1 >= t)
        {
            if(ed[v])
                ans = max(ans,DFS(v,d+1) + w);
        }
        else ans = max(ans,DFS(v,d+1) + w);
    }
    
    return pr[u][d] = ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10702 - Travelling Salesman.INP","r",stdin);
    freopen("10702 - Travelling Salesman.OUT","w",stdout);
    #endif
    bool blk = 0;
    while(scanf(" %d %d %d %d ",&c,&st,&e,&t) && c)
    {
        if(blk) puts("");
        blk = 1;
        
        fr(i,1,c)
        {
            adj[i].clear();
            ed[i] = 0;
        }
        
        fr(i,1,c)
        {
            fr(j,1,c)
            {
                int w;
                read(w);
                if(i == j) continue;
                
                adj[i].pb(mp(j,w));
            }
        }
        
        rep(i,e)
        {
            int u;
            read(u);
            ed[u] = 1;
        }
        
        fr(i,1,c)
            fr(j,0,t)
                pr[i][j] = -1;
        
        cout << DFS(st,0) << endl;
    }
    
    return 0;
}
