//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10484 - Divisibility of Factors
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
#define maxN 100

ll n,d;
vi primes;
bool check[maxN+5];
int cN[maxN+5], cD[maxN+5];

void sieve()
{
    fr(i,0,maxN)
        check[i] = true;
    
    fr(i,2,maxN)
    {
        if(check[i])
        {
            //DEBUG(i);
            primes.pb(i);
            for(ll j = i ; i*j <= maxN ; j++)
                check[i*j] = false;
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10484 - Divisibility of Factors.INP","r",stdin);
    freopen("10484 - Divisibility of Factors.OUT","w",stdout);
    #endif
    sieve();
    while(read2(n,d) && d)
    {
        d = abs(d);
        if(n == 0 || n == 1)
        {
            if(d == 1) puts("1");
            else puts("0");
            continue;
        }
        
        fr(i,0,100) cN[i] = cD[i] = 0;
        for(int i = 2 ; i <= n ; i++)
        {
            int k = i;
            for(int j = 0 ; j < sz(primes) && primes[j] <= k ; j++)
                while(k % primes[j] == 0)
                {
                    k /= primes[j];
                    cN[primes[j]]++;
                }
        }
        
        for(int j = 0 ; j < sz(primes) && primes[j] <= d ; j++)
            while(d % primes[j] == 0)
            {
                d /= primes[j];
                cD[primes[j]]++;
            }
        
        if(d != 1)
        {
            puts("0");
            continue;
        }
        
        bool ok = true;
        ll ans = 1;
        fr(i,2,100)
        {
            if((cN[i] - cD[i]) < 0)
            {
                ok = false;
                break;
            }
            ans *= (cN[i] - cD[i] + 1);
        }
        if(!ok) ans = 0;
        cout << ans << endl;
    }
    
    return 0;
}
