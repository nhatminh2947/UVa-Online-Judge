//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10616 - Divisible Group Sums
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

ll dp[205][15][25], a[205];
int d;

ll mod(ll n,ll m)
{
    return ((n % m) + m ) % m;
}

ll solve(int n, int m, int r)
{
    if(!n && m)
        return 0;
    
    if(!m) return dp[n][m][r] = (r == 0);
    
    if(dp[n][m][r] != -1) return dp[n][m][r];
    
    return dp[n][m][r] = solve(n-1,m-1,mod(r+a[n],d)) + solve(n-1,m,r);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10616 - Divisible Group Sums.INP","r",stdin);
    freopen("10616 - Divisible Group Sums.OUT","w",stdout);
    #endif
    int n,q,m;
    int tcs = 1;
    while(scanf(" %d %d ",&n,&q) && n)
    {
        printf("SET %d:\n",tcs++);
        fr(i,1,n) scanf(" %lld ",&a[i]);
        
        fr(t,1,q)
        {
            scanf(" %d %d ",&d,&m);
            
            fr(i,0,n) fr(j,0,m) fr(k,0,d) dp[i][j][k] = -1;
            
            printf("QUERY %d: %lld\n",t,solve(n,m,d));
        }
    }
    
    return 0;
}
