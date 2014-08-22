//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11690 - Money Matters
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

int val[maxN+5];
int pSet[maxN+5];
int n,m;

void init(int k)
{
    rep(i,k)
        pSet[i] = i;
}

int findSet(int u)
{
    if(pSet[u] == u) return u;
    return pSet[u] = findSet(pSet[u]);
}

void unionSet(int u, int v)
{
    int fu = findSet(u);
    int fv = findSet(v);
    if(fu != fv)
        val[fv] += val[fu];
    pSet[fu] = fv;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11690 - Money Matters.INP","r",stdin);
    freopen("11690 - Money Matters.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    fr(t,1,tcs)
    {
        scanf(" %d %d ",&n,&m);
        init(n);
        rep(i,n)
            scanf(" %d ",&val[i]);
        
        rep(i,m)
        {
            int u,v;
            scanf(" %d %d",&u,&v);
            
            unionSet(u,v);
        }
        
        bool ok = true;
        rep(i,n)
            if(val[findSet(i)] != 0)
            {
                ok = false;
                break;
            }
        
        ok ? puts("POSSIBLE") : puts("IMPOSSIBLE");
    }
    
    return 0;
}
