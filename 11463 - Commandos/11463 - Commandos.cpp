//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11463 - Commandos
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

vi adj[105];
int distDesti[105], distStart[105];
int n,r;

inline void BFS(int st)
{
    rep(i,n) distStart[i] = INF;
    
    queue<int> q;
    q.push(st);
    distStart[st] = 0;
    
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        
        int len = sz(adj[u]);
        
        rep(i,len)
        {
            int v = adj[u][i];
            if(distStart[v] == INF)
            {
                q.push(v);
                distStart[v] = distStart[u] + 1;
            }
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11463 - Commandos.INP","r",stdin);
    freopen("11463 - Commandos.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    
    fr(t,1,tcs)
    {
        scanf(" %d %d ",&n,&r);
        
        rep(i,n) adj[i].clear();
        
        int u,v;
        rep(i,r)
        {
            scanf(" %d %d ",&u,&v);
            
            adj[u].pb(v);
            adj[v].pb(u);
        }
        
        int ans = -INF;
        
        scanf(" %d %d ",&u,&v);
        
        BFS(v);
        
        rep(i,n) distDesti[i] = distStart[i];
        
        BFS(u);
        
        rep(i,n) ans = max(ans,distStart[i]+distDesti[i]);
        
        printf("Case %d: %d\n",t,ans);
    }

    return 0;
}