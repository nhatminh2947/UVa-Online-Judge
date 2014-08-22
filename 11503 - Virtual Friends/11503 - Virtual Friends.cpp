//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11503 - Virtual Friends
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
#define maxN 200000

int n;
int pSet[maxN+5];
int setSize[maxN+5];
map<string,int> m;

void initSet(int n)
{
    fr(i,1,n)
    {
        setSize[i] = 1;
        pSet[i] = i;
    }
}

int findSet(int u)
{
    if(pSet[u] == u) return u;
    return pSet[u] = findSet(pSet[u]);
}

bool isSameSet(int u, int v)
{
    return findSet(u) == findSet(v);
}

void unionSet(int u, int v)
{
    if(!isSameSet(u,v))
        setSize[findSet(v)] += setSize[findSet(u)];
    pSet[findSet(u)] = findSet(v);
}

int sizeOfSet(int u)
{
    return setSize[findSet(u)];
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11503 - Virtual Friends.INP","r",stdin);
    freopen("11503 - Virtual Friends.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    
    rep(t,tcs)
    {
        scanf(" %d ",&n);
        
        m.clear();
        initSet(2*n);
        
        int k = 0;
        rep(i,n)
        {
            string u,v;
            read2(u,v);
            
            if(!m.count(u)) m[u] = ++k;
            if(!m.count(v)) m[v] = ++k;
            
            unionSet(m[u],m[v]);
            
            printf("%d\n",sizeOfSet(m[u]));
        }
    }
    
    return 0;
}
