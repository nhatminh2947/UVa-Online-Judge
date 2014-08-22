//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11466 - Largest Prime Divisor
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
#define maxN 10000000

ll n;
bool check[maxN+5];
vector<ll> p;

void sieve()
{
    fr(i,1,maxN) check[i] = true;
    
    for(ll i = 2 ; i <= maxN ; i++)
    {
        if(check[i])
        {
            p.pb(i);
            for(ll j = 2 ; i*j <= maxN ; j++)
                check[i*j] = false;
        }
    }
    //DEBUG(sz(p));
}

int main()
{
    freopen("11466 - Largest Prime Divisor.INP","r",stdin);
    freopen("11466 - Largest Prime Divisor.OUT","w",stdout);
    
    sieve();
    while(scanf("%lld",&n) && n)
    {
        if(n < 0) n = -n;
        
        //DEBUG(n);
        int cnt = 0;
        ll ans = -INF;
        for(int i = 0 ; i < sz(p) && p[i] <= n ; i++)
        {
            if(n%p[i] == 0)
            {
                cnt++;
                ans = p[i];
            }
            while(n%p[i] == 0)
                n /= p[i];
        }
            
        if(n == 1)
        {
            if (cnt > 1) printf("%lld\n",ans);
            else printf("-1\n");
        }
        else
        {
            if (cnt > 0) printf("%lld\n",n);
            else printf("-1\n");
        }
    }

    return 0;
}