//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 583 - Prime Factors
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

ll n;
bool check[47005];
vi primes;

void sieve()
{   
    for(int i = 0 ; i <= 47000 ; i++)
        check[i] = true;
    
    for(ll i = 2 ; i <= 47000 ; i++)
        if(check[i])
        {
            primes.pb(i);
            for(ll j = i ; i*j <= 47000 ; j++)
                check[i*j] = false;
        }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("583 - Prime Factors.INP","r",stdin);
    freopen("583 - Prime Factors.OUT","w",stdout);
    #endif
    
    sieve();
    while(read(n) && n)
    {
        printf("%lld = ",n);
        bool x = false;
        if(n < 0)
        {
            printf("-1");
            x = true;
            n = -n;
        }
        
        if(n == 1)
        {
            if(x) printf(" x ");
            printf("1\n");
            continue;
        }
        
        for(int i = 0 ; i < sz(primes) && primes[i] <= n ; i++)
        {
            while(n % primes[i] == 0)
            {
                if(x) printf(" x ");
                x = true;
                printf("%d",primes[i]);
                n /= primes[i];
            }
        }
        
        if(n != 1)
        {
            if(x) printf(" x ");
            printf("%lld",n);
        }
        
        printf("\n");
    }
    
    return 0;
}
