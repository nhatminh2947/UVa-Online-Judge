//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 884 - Factorial Factors
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

bool check[maxN+5];
vi primes;
int dp[maxN+5];

void sieve()
{
    //cout << "BB" << endl;
    for(int i = 0 ; i <= maxN ; i++)
        check[i] = true;
    
    for(ll i = 2 ; i <= 1000 ; i++)
        if(check[i])
        {
            primes.pb(i);
            for(ll j = i ; i*j <= maxN ; j++)
                check[i*j] = false;
        }
    //DEBUG(primes.size());
}

void solve()
{
    fr(i,1,maxN) dp[i] = 0;
    
    fr(i,2,maxN)
    {
        if(!dp[i]) dp[i] = 1;
        
        for(ll j = 2 ; i*j <= maxN ; j++)
            dp[i*j] = dp[i]+1;
    }
    
    fr(i,2,maxN)
    {
        dp[i] += dp[i-1];
    }
}

void preCal()
{
    sieve();
    dp[0] = 0;
    dp[1] = 0;
    for(int k = 2 ; k <= 1000000 ; k++)
    {
        //DEBUG(k);
        dp[k] = 0;
        int n = k;
        for(int i = 0 ; i < sz(primes) && primes[i]*primes[i] <= n ; i++)
        {
            while(n % primes[i] == 0)
            {
                n /= primes[i];
                dp[k]++;
            }
        }
        
        if(n != 1) dp[k]++;
        dp[k] += dp[k-1];
    }
}

void bestChoice()
{
    sieve();
    //cout << "AA" << endl;
    //fr(i,0,maxN) dp[i] = 0;
    dp[2] = 1;
    fr(i,3,maxN)
    {
        if(check[i])
        {
            dp[i] = dp[i-1] + 1;
            continue;
        }
        
        int k = 0;
        while(i%primes[k]) k++;
        dp[i] = dp[i-1] + (dp[i/primes[k]] - dp[i/primes[k] - 1]) + 1;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("884 - Factorial Factors.INP","r",stdin);
    freopen("884 - Factorial Factors.OUT","w",stdout);
    #endif
    
    //preCal();
    //solve();
    bestChoice();
    int n;
    while(read(n))
    {
        printf("%d\n",dp[n]);
    }
    
    return 0;
}
