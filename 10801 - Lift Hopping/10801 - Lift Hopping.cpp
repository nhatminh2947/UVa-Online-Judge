//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10801 - Lift Hopping
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

int T[10];
int n,k;
int dist[10][105];
vii adj[105];
set< pair<int,ii> > s;

int Dijsktra()
{
    while(!s.empty())
    {
        pair<int,ii> p = *s.begin();
        
        int e = p.ss.ff;
        int u = p.ss.ss;
        
        if(u == k) return dist[e][u];
        
        s.erase(p);
        
        rep(i,sz(adj[u]))
        {
            int v = adj[u][i].ff;
            int ee = adj[u][i].ss;
            //printf("e = %3d u = %3d dist = %3d ---> ee = %3d v = %3d dist = %3d\n",e,u,dist[e][u],ee,v,dist[ee][v]);
            if((u != v && e == ee) || (u == v && e != ee))
            {
                //cout << "AAA" << endl;
                int d = abs(u-v)*T[e] + ((e == ee) ? 0 : 60);
                if(dist[e][u] + d < dist[ee][v])
                {
                    if(dist[ee][v] != INF) s.erase(mp(dist[ee][v],mp(ee,v)));
                    dist[ee][v] = dist[e][u] + d;
                    s.insert(mp(dist[ee][v],mp(ee,v)));
                }
            }
        }
    }
    
    return -1;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10801 - Lift Hopping.INP","r",stdin);
    freopen("10801 - Lift Hopping.OUT","w",stdout);
    #endif
    
    while(scanf(" %d %d ",&n,&k) == 2)
    {
        fr(i,1,n) scanf(" %d ",&T[i]);
        
        s.clear();
        fr(i,0,99)
        {
            adj[i].clear();
            fr(j,0,n)
                dist[j][i] = INF;
        }
        
        fr(i,1,n)
        {
            //DEBUG(i);
            char str[1000];
            gets(str);
            int a[1000];
            int cnt = 1;
            a[cnt] = 0;
            //DEBUG(s);
            for(int j = 0 ; str[j] ; j++)
            {
                if(str[j] == ' ')
                    a[++cnt] = 0;
                else a[cnt] = a[cnt]*10 + str[j] - '0';
                
            }
            
            fr(u,1,cnt)
                if(a[u] == 0)
                {
                    s.insert(mp(0,mp(i,0)));
                    dist[i][0] = 0;
                }
            
            fr(u,1,cnt)
                fr(v,u,cnt)
                {
                    adj[a[u]].pb(mp(a[v],i));
                    adj[a[v]].pb(mp(a[u],i));
                }
            //cout << "AAA" << endl;
        }
        
        int ans = Dijsktra();
        
        if(ans == -1) puts("IMPOSSIBLE");
        else printf("%d\n",ans);
    }
    
    return 0;
}
