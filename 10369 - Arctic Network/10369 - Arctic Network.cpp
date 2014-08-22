//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10369 - Arctic Network
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

int s,p;
int x[505],y[505];
double dist[505][505];
int pSet[1000000];
vii a;

bool cmp(ii u, ii v)
{
    return dist[u.ff][u.ss] < dist[v.ff][v.ss];
}

int findSet(int u)
{
    if(pSet[u] == u) return u;
    return pSet[u] = findSet(pSet[u]);
}

void unionSet(int u, int v)
{
    pSet[findSet(u)] = findSet(v);
}

void initSet(int k)
{
    fr(i,0,k) pSet[i] = i;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10369 - Arctic Network.INP","r",stdin);
    freopen("10369 - Arctic Network.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    
    fr(t,1,tcs)
    {
        scanf(" %d %d ",&s,&p);
        a.clear();
        rep(i,p)
            scanf("%d %d",&x[i],&y[i]);
        
        fr(i,0,p-2)
            fr(j,i+1,p-1)
            {
                dist[i][j] = dist[j][i] = sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]));
                a.pb(mp(i,j));
            }
        //DEBUG(sz(a));
        initSet(p);
        sort(all(a),cmp);
        double ans = 0;
        int done = 0;
        rep(i,sz(a))
        {
            //cout << "AA" << endl;
            int u = a[i].ff;
            int v = a[i].ss;
            
            int fu = findSet(u);
            int fv = findSet(v);
            
            if(fu != fv)
            {
                ans = max(ans,dist[u][v]);
                unionSet(u,v);
                done++;
            }
            
            if(done == (p-s)) break;
        }
        
        printf("%.2lf\n",ans);
    }
    
    return 0;
}
