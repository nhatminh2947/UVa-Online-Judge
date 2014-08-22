//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 988 - Many Paths, One Destination
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
#define maxN 35

int cnt[maxN+5];
vector<int> adj[maxN+5];
int n;

int DFS(int u)
{
    if(cnt[u]) return cnt[u];
    
    int ways = 0;
    
    int len = adj[u].size();
    rep(i,len)
    {
        int v = adj[u][i];
        ways += DFS(v);
    }
    
    return cnt[u] = ways;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("988 - Many Paths, One Destination.INP","r",stdin);
    freopen("988 - Many Paths, One Destination.OUT","w",stdout);
    #endif
    
    bool blank = false;
    while(scanf(" %d ",&n) == 1)
    {
        if(blank) printf("\n");
        blank = true;
        rep(u,n)
        {
            adj[u].clear();
            cnt[u] = 0;
            int m,v;
            scanf(" %d ",&m);
            rep(i,m)
            {
                scanf(" %d ",&v);
                adj[u].pb(v);
            }
            
            if(m == 0) cnt[u] = 1;
        }
        
        printf("%d\n",DFS(0));
    }
    
    return 0;
}