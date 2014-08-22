//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10842 - Traffic Flow
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

int n,m;
int dist[105][105];
int pSet[105];
vii lst;

void initSet(int k)
{
    fr(i,0,k) pSet[i] = i;
}

int findSet(int u)
{
    if(u == pSet[u]) return u;
    return pSet[u] = findSet(pSet[u]);
}

bool cmp(ii u, ii v)
{
    return dist[u.ff][u.ss] > dist[v.ff][v.ss];
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10842 - Traffic Flow.INP","r",stdin);
    freopen("10842 - Traffic Flow.OUT","w",stdout);
    #endif
    
    int tcs;
    read(tcs);
    
    fr(t,1,tcs)
    {
        read2(n,m);
        fr(i,0,n)
            fr(j,0,n)
                dist[i][j] = -1;
        lst.clear();
        rep(i,m)
        {
            int u,v,w;
            read3(u,v,w);
            
            if(dist[u][v] == -1)
                lst.pb(mp(u,v));
            dist[u][v] = dist[v][u] = max(dist[u][v],w);
        }
        
        sort(all(lst),cmp);
        initSet(n);
        int ans = INF;
        int done = 0;
        rep(i,sz(lst))
        {
            int u = lst[i].ff;
            int v = lst[i].ss;
            
            //DEBUG(u);
            //DEBUG(v);
            int fu = findSet(u);
            int fv = findSet(v);
            
            if(fu != fv)
            {
                ans = min(ans,dist[u][v]);
                pSet[fu] = fv;
                done++;
            }
            
            if(done == n-1)
                break;
        }
        
        printf("Case #%d: %d\n",t,ans);
    }
    
    return 0;
}
