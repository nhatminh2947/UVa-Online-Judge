//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11080 - Place the Guards
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

vi adj[205];
bool vis[205],dist[205];
int n,m;

int BFS(int st)
{
    queue<int> q;
    q.push(st);
    vis[st] = true;
    dist[st] = false;
    int zero = 0;
    int one = 0;
    
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        if(dist[u]) one++;
        else zero++;
        
        rep(i,sz(adj[u]))
        {
            int v = adj[u][i];
            
            if(!vis[v])
            {
                vis[v] = true;
                dist[v] = !dist[u];
                q.push(v);
            }
            else if(dist[u] == dist[v])
                return -1;
        }
    }
    
    return min(zero,max(one,1));
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11080 - Place the Guards.INP","r",stdin);
    freopen("11080 - Place the Guards.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    rep(t,tcs)
    {
        scanf(" %d %d ",&n,&m);
        
        if(m == 0)
        {
            printf("%d\n",n);
            continue;
        }
        
        rep(i,n)
        {
            vis[i] = false;
            adj[i].clear();
        }
        
        rep(i,m)
        {
            int u,v;
            scanf(" %d %d ",&u,&v);
            adj[u].pb(v);
            adj[v].pb(u);
        }
        //DEBUG(m);
        int ans = 0;
        rep(i,n) if(!vis[i])
        {
            //DEBUG(i);
            int k = BFS(i);
            if(k == -1)
            {
                ans = -1;
                break;
            }
            
            ans += k;
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
