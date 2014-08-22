//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10158 - War
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
#define maxN 10000

int n;
int pSet[2*maxN+5];

int op(int u)
{
    if(u < 10000) return u + 10000;
    return u - 10000;
}

void init(int k)
{
    fr(i,0,k)
    {
        pSet[i] = i;
        pSet[op(i)] = op(i);
    }
}

int findSet(int u)
{
    if(u == pSet[u]) return u;
    return pSet[u] = findSet(pSet[u]);
}

void unionSet(int u, int v)
{
    pSet[findSet(u)] = findSet(v);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10158 - War.INP","r",stdin);
    freopen("10158 - War.OUT","w",stdout);
    #endif
    
    while(scanf("%d",&n) == 1)
    {
        init(n);
        int c,u,v;
        while(scanf("%d %d %d",&c,&u,&v) && c)
        {
            if(c == 1)
            {
                if(findSet(u) == findSet(op(v)) || findSet(op(u)) == findSet(v)) puts("-1");
                else
                {
                    unionSet(u,v);
                    unionSet(op(u),op(v));
                }
            }
            else if(c == 2)
            {
                if(findSet(u) == findSet(v) || findSet(op(u)) == findSet(op(v))) puts("-1");
                else
                {
                    unionSet(u,op(v));
                    unionSet(op(u),v);
                }
            }
            else if(c == 3)
            {
                if(findSet(u) == findSet(v) || findSet(op(u)) == findSet(op(v)))
                    puts("1");
                else puts("0");
            }
            else if(c == 4)
            {
                if(findSet(u) == findSet(op(v)) || findSet(op(u)) == findSet(v))
                    puts("1");
                else puts("0");
            }
        }
    }
    
    
    return 0;
}
