//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 793 - Network Connections
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
#define maxN 1000000

int n;
int pSet[maxN+5];

void initSet(int k)
{
    fr(i,1,k) pSet[i] = i; 
}

int findSet(int u)
{
    if(u == pSet[u]) return u;
    return pSet[u] = findSet(pSet[u]);
}

bool isSameSet(int u, int v)
{
    return findSet(u) == findSet(v);
}

void unionSet(int u, int v)
{
    pSet[findSet(u)] = findSet(v);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("793 - Network Connections.INP","r",stdin);
    freopen("793 - Network Connections.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    
    rep(t,tcs)
    {
        if(t) puts("");
        scanf(" %d ",&n);
        initSet(n);
        int successfull,unsuccessfull;
        successfull = unsuccessfull = 0;
        char s[1000];
        while(gets(s) && s[0] != '\0')
        {
            char c;
            int u,v;
            sscanf(s," %c %d %d ",&c,&u,&v);
            
            if(c == 'c')
                unionSet(u,v);
            else
            {
                if(isSameSet(u,v)) successfull++;
                else unsuccessfull++;
            }
        }
        
        printf("%d,%d\n",successfull,unsuccessfull);
    }
    
    return 0;
}
