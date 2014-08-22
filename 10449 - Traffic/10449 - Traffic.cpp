//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10449 - Traffic
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

int n,m,q;
vii adj[maxN+5];
int val[maxN+5];
int dist[maxN+5];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10449 - Traffic.INP","r",stdin);
    freopen("10449 - Traffic.OUT","w",stdout);
    #endif
    
    int tcs = 1;
    while(scanf(" %d ",&n) == 1)
    {
        fr(i,1,n)
        {
            adj[i].clear();
            scanf(" %d ",&val[i]);
        }
        
        scanf(" %d ",&m);
        rep(i,m)
        {
            int u,v;
            scanf(" %d %d ",&u,&v);
            
            int w = (val[v] - val[u])*(val[v] - val[u])*(val[v] - val[u]);
            adj[u].pb(mp(v,w));
        }
        
        printf("Set #%d\n",tcs++);
        
        fr(u,1,200) dist[u] = INF;
        dist[1] = 0;
            
        rep(i,5*n)
        {
            fr(u,1,n)
            {
                rep(j,sz(adj[u]))
                {
                    int v = adj[u][j].ff;
                    int d = adj[u][j].ss;
                    
                    dist[v] = min(dist[v],dist[u]+d);
                }
                //printf("dist[%d] = %d\n",u,dist[u]);
            }
            //puts("");
        }
        
        bool check = false;
        for(int u = 1 ; u <= n && !check ; u++)
            rep(j,sz(adj[u]))
            {
                int v = adj[u][j].ff;
                int d = adj[u][j].ss;
                
                if(dist[u] + d < dist[v])
                {
                    check = true;
                    break;
                }
            }
        
        scanf("%d",&q);
        rep(t,q)
        {
            int d;
            scanf(" %d ",&d);
            
            if(3 <= dist[d] && dist[d] < INF) printf("%d",dist[d]);
            else printf("?");
            printf("\n");
        }
    }
    
    return 0;
}
