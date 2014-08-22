//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10147 - Highways
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
int pSet[1005];
int x[1005],y[1005];
double d[1005][1005];
vii lst;

double dist(int u, int v)
{
    return sqrt((x[u] - x[v])*(x[u] - x[v]) + (y[u] - y[v])*(y[u] - y[v]));
}

bool cmp(ii u, ii v)
{
    return d[u.ff][u.ss] < d[v.ff][v.ss];
}

int findSet(int u)
{
    if(u == pSet[u]) return u;
    return pSet[u] = findSet(pSet[u]);
}

void initSet(int k)
{
    fr(i,1,k)
        pSet[i] = i;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10147 - Highways.INP","r",stdin);
    freopen("10147 - Highways.OUT","w",stdout);
    #endif
    
    int tcs;
    read(tcs);
    
    rep(t,tcs)
    {
        if(t) printf("\n");
        read(n);
        fr(i,1,n)
            read2(x[i],y[i]);
        
        lst.clear();
        initSet(n);
        int done = 0;
        
        fr(i,1,n-1)
            fr(j,i+1,n)
            {
                d[i][j] = d[j][i] = dist(i,j);
                lst.pb(mp(i,j));
                //printf("dist[%2d][%2d] = %.3lf\n",i,j,d[i][j]);
            }
        
        read(m);
        rep(i,m)
        {
            int u,v;
            read2(u,v);
            
            int fu = findSet(u);
            int fv = findSet(v);
            
            if(fu != fv)
            {
                pSet[fu] = fv;
                done++;
            }
        }
        
        if(done == n-1)
        {
            puts("No new highways need");
            continue;
        }
        
        sort(all(lst),cmp);
        
        rep(i,sz(lst))
        {
            int u = lst[i].ff;
            int v = lst[i].ss;
            
            int fu = findSet(u);
            int fv = findSet(v);
            
            if(fu != fv)
            {
                pSet[fu] = fv;
                done++;
                printf("%d %d\n",u,v);
            }
            
            if(done == n-1)
                break;
        }
    }
    
    return 0;
}
