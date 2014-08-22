//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1174 - IP-TV
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

int n,r;
int pSet[2005];
int dist[2005][2005];
vii lst;
map<string,int> m;

void initSet(int k)
{
    fr(i,1,k) pSet[i] = i;
}

bool cmp(ii u, ii v)
{
    return dist[u.ff][u.ss] < dist[v.ff][v.ss];
}

int findSet(int u)
{
    if(u == pSet[u]) return u;
    return pSet[u] = findSet(pSet[u]);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1174 - IP-TV.INP","r",stdin);
    freopen("1174 - IP-TV.OUT","w",stdout);
    #endif
    
    int tcs;
    read(tcs);
    
    rep(t,tcs)
    {
        if(t) printf("\n");
        read2(n,r);
        
        m.clear();
        lst.clear();
        
        rep(i,r)
        {
            string u,v;
            int w;
            
            read3(u,v,w);
            
            if(!m.count(u))
                m[u] = sz(m);
            if(!m.count(v))
                m[v] = sz(m);

            int mu = m[u];
            int mv = m[v];
            
            dist[mu][mv] = dist[mv][mu] = w;
            lst.pb(mp(mu,mv));
        }
        
        initSet(n);
        sort(all(lst),cmp);
        
        int ans = 0;
        int done = 0;
        
        rep(i,sz(lst))
        {
            int u = lst[i].ff;
            int v = lst[i].ss;
            
            int fu = findSet(u);
            int fv = findSet(v);
            
            if(fu != fv)
            {
                ans += dist[u][v];
                pSet[fu] = fv;
                done++;
            }
            
            if(done == n-1)
                break;
        }
        
        cout << ans << endl;
    }
    
    return 0;
}
