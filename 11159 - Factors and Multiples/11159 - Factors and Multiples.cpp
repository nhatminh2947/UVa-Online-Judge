//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11159 - Factors and Multiples
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

vi a,b;
int n,m;
int owner[205];
bool vis[205];
vi adj[105];

void reset()
{
    a.clear();
    b.clear();
    
    rep(i,n) adj[i].clear();
}

int solve(int u)
{
    if(vis[u]) return 0;
    
    vis[u] = true;
    
    rep(i,sz(adj[u]))
    {
        int v = adj[u][i];
        
        if(owner[v] == -1 || solve(owner[v]))
        {
            owner[v] = u;
            return 1;
        }
    }
    
    return 0;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11159 - Factors and Multiples.INP","r",stdin);
    freopen("11159 - Factors and Multiples.OUT","w",stdout);
    #endif
    
    int tcs;
    
    scanf(" %d ",&tcs);
    
    fr(t,1,tcs)
    {
        scanf(" %d ",&n);
        
        reset();
        
        rep(i,n)
        {
            int x;
            scanf(" %d ",&x);
            a.pb(x);
        }
        
        scanf(" %d ",&m);
        rep(i,m)
        {
            int x;
            scanf(" %d ",&x);
            b.pb(x);
        }
        
        rep(i,n)
            rep(j,m)
            {
                if(a[i] == 0)
                {
                    if(b[j] == 0)
                        adj[i].pb(j+n);
                    continue;
                }
                
                if(b[j]%a[i] == 0)
                {
                    adj[i].pb(j+n);
                    //printf("%d %d\n",i,j+n);
                }
            }
        
        int cnt = 0;
        int v = n+m;
        rep(i,v) owner[i] = -1;
        rep(i,n)
        {
            rep(j,n) vis[j] = false;
            cnt += solve(i);
        }
        
        printf("Case %d: %d\n",t,cnt);
    }
    
    return 0;
}

