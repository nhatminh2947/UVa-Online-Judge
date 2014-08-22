//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11655 - Waterland
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
#define mod 100000

vi adj[5005];
int n,m;
int cnt[5005];
int reachable[5005];

int DFS(int u)
{
    if(cnt[u] != -1) return cnt[u]%mod;
    
    if(u == n)
    {
        reachable[n] = 1;
        return cnt[n] = 1;
    }
    
    int sum = 0;
    
    rep(i,sz(adj[u]))
    {
        int v = adj[u][i];
        sum = (sum%mod + DFS(v)%mod)%mod;
        reachable[u] = (reachable[u]%mod + reachable[v]%mod)%mod;
    }
    
    return cnt[u] = (sum%mod+1%mod)%mod;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11655 - Waterland.INP","r",stdin);
    freopen("11655 - Waterland.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    
    fr(t,1,tcs)
    {
        scanf(" %d %d ",&n,&m);
        
        fr(i,1,n)
        {
            reachable[i] = 0;
            cnt[i] = -1;
            adj[i].clear();
        }
        
        rep(i,m)
        {
            int u,v;
            scanf(" %d %d ",&u,&v);
            adj[u].pb(v);
        }
        
        DFS(1);
        
        printf("Case %d: %d %d\n",t,(cnt[1]-1)%mod,reachable[1]%mod);
    }
    
    return 0;
}
