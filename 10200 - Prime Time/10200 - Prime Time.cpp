//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10200 - Prime Time
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
#define maxN 10000

bool check[maxN+5];
int cnt[maxN+5];
vi primes;
int a,b;

void sieve()
{
    fr(i,0,maxN)
        check[i] = true;
        
    fr(i,2,maxN)
        if(check[i])
        {
            primes.pb(i);
            for(ll j = i ; i*j <= maxN ; j++)
                check[i*j] = false;
        }
    //DEBUG(sz(primes));
}

ll f(ll x)
{
    return x*x + x + 41;
}

void preCal()
{
    sieve();
    cnt[0] = 1;
    fr(i,1,10000)
    {
        bool ok = true;
        ll m = f((ll)i);
        //DEBUG(m);
        for(int j = 0 ; j < sz(primes) && m > primes[j] ; j++)
            if(m % primes[j] == 0)
            {
                ok = false;
                break;
            }
        
        if(ok) cnt[i] = cnt[i-1] + 1;
        else cnt[i] = cnt[i-1];
        printf("cnt[%d] = %d\n",i,cnt[i]);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10200 - Prime Time.INP","r",stdin);
    freopen("10200 - Prime Time.OUT","w",stdout);
    #endif
    
    preCal();
    while(scanf(" %d %d ",&a,&b) == 2)
    {
        int p;
        int total = b - a + 1;
        if(a == 0) p = cnt[b];
        else p = cnt[b] - cnt[a-1];
        
        printf("%.2lf\n",100.0*p/total + eps);
    }
    
    return 0;
}
