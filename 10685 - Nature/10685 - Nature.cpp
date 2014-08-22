//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10685 - Nature
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

int pSet[5005];
int sizeSet[5005];
map<string,int> m;
int c,r;

void initSet(int k)
{
    fr(i,1,k)
    {
        sizeSet[i] = 1;
        pSet[i] = i;
    }
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
    if(fu != fv) sizeSet[fv] += sizeSet[fu];
    pSet[findSet(u)] = findSet(v);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10685 - Nature.INP","r",stdin);
    freopen("10685 - Nature.OUT","w",stdout);
    #endif
    
    while(scanf(" %d %d ",&c,&r) && c)
    {
        m.clear();
        initSet(c);
        fr(i,1,c)
        {
            string s;
            read(s);
            
            m[s] = i;
        }
        
        rep(i,r)
        {
            string u,v;
            read2(u,v);
            
            unionSet(m[u],m[v]);
        }
        
        int ans = -INF;
        fr(i,1,c) ans = max(ans,sizeSet[findSet(i)]);
        
        printf("%d\n",ans);
    }
    
    return 0;
}
