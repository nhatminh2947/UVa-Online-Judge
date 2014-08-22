//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10419 - Sum-up the Primes
// Verdict: 
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

int dp[15][1005];
int ans[15];
vi primes;
int n,m;
bool ok;

void preCal()
{
    primes.pb(2);
    fr(i,3,300)
    {
        bool ok = true;
        fr(j,2,sqrt(i))
            ok &= (i%j != 0);
        if(ok)
        {
            primes.pb(i);
            primes.pb(i);
        }
    }
}

void solve(int st, int p, int sum)
{
    if(ok) return;
    
    if(p == m)
    {
        if(sum == 0)
        {
            ok = true;
            rep(i,p)
            {
                if(i) printf("+");
                printf("%d",ans[i]);
            }
        }
        return;
    }
    
    for(int i = st ; i < sz(primes) && sum - primes[i] >= 0 ; i++)
    {
        ans[p] = primes[i];
        solve(i+1,p+1,sum - primes[i]);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10419 - Sum-up the Primes.INP","r",stdin);
    freopen("10419 - Sum-up the Primes.OUT","w",stdout);
    #endif
    
    preCal();
    
    int tcs = 0;
    while(read2(n,m) && n)
    {
        printf("CASE %d:\n",++tcs);
        ok = false;
        solve(0,0,n);
        
        if(!ok) printf("No Solution.");
        puts("");
    }
    
    return 0;
}
