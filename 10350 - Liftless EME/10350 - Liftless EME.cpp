//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10350 - Liftless EME
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

char cs[15];
int h[maxN+5];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10350 - Liftless EME.INP","r",stdin);
    freopen("10350 - Liftless EME.OUT","w",stdout);
    #endif
    
    while(gets(cs))
    {
        int n,m;
        scanf(" %d %d ",&n,&m);
        
        rep(i,m*n) h[i] = INF;
        
        rep(i,m) h[i] = 0;
        
        int ans = INF;
        rep(k,n-1)
            rep(i,m)
                rep(j,m)
                {
                    int w;
                    scanf(" %d ",&w);
                    
                    int u = k*m + i;
                    int v = (k+1)*m + j;
                    
                    h[v] = min(h[v],h[u]+w+2);
                    if(k+1 == n-1) ans = min(ans,h[v]);
                }
                
        printf("%s\n%d\n",cs,ans);
    }
    
    return 0;
}
