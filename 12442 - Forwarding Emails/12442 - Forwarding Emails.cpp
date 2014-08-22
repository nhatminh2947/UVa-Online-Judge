//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 12442 - Forwarding Emails
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
#define maxN 50000

stack<int> s;
vector<int> adjSCC[maxN+5];
bool onStack[maxN+5];
int ind[maxN+5],lowlink[maxN+5],SCC[maxN+5],cnt[maxN+5],adj[maxN+5],minNode[maxN+5];
int id,scc;

void Tarjan(int u)
{
    lowlink[u] = ind[u] = id++;
    
    s.push(u);
    onStack[u] = true;
    int v = adj[u];
    
    if(ind[v] == -1)
    {
        Tarjan(v);
        lowlink[u] = min(lowlink[u],lowlink[v]);
    }
    else if(onStack[v])
        lowlink[u] = min(lowlink[v],ind[u]);
    
    if(lowlink[u] == ind[u])
    {
        ++scc;
        do
        {
            v = s.top();
            s.pop();
            onStack[v] = false;
            SCC[v] = scc;
            cnt[scc]++;
            minNode[scc] = min(minNode[scc],v);
        }while(u != v);
    }
}

void reset()
{
    scc = id = 0;
    while(!s.empty())
        s.pop();
    
    for(int i = 0 ; i <= 50000 ; i++)
    {
        onStack[i] = false;
        lowlink[i] = ind[i] = -1;
        minNode[i] = INF;
        cnt[i] = 0;
        adj[i] = i;
        adjSCC[i].clear();
    }
}

int DFS(int u)
{
    int res = cnt[u];
    rep(i,sz(adjSCC[u]))
    {
        int v = adjSCC[u][i];
        res += DFS(v);
    }
    
    return res;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("12442 - Forwarding Emails.INP","r",stdin);
    freopen("12442 - Forwarding Emails.OUT","w",stdout);
    #endif
    
    int tcs;
    
    scanf(" %d ",&tcs);
    
    fr(t,1,tcs)
    {
        reset();
        int n;
        
        scanf(" %d ",&n);
        
        rep(i,n)
        {
            int u,v;
            scanf(" %d %d ",&u,&v);
            adj[u] = v;
        }
        
        fr(i,1,n) if(ind[i] == -1) Tarjan(i);
        
        int ans = 0;
        int ma = -INF;
        
        fr(i,1,n) if(SCC[i] != SCC[adj[i]]) adjSCC[SCC[i]].pb(SCC[adj[i]]);
        
        fr(i,1,scc)
        {
            int k = DFS(i);
            if(ma < k || (ma == k && minNode[i] < ans))
            {
                ma = k;
                ans = minNode[i];
            }
        }
        
        printf("Case %d: %d\n",t,ans);
    }

    return 0;
}