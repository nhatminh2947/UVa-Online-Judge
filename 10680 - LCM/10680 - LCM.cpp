//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10680 - LCM
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

//8 huong
//int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1};
//int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};

//horse
//int dx[] = {-2,-2,-1,-1, 1, 1, 2, 2};
//int dy[] = {-1, 1,-2, 2,-2, 2,-1, 1};

const int dx[] = {-1, 0, 0, 1};
const int dy[] = { 0,-1, 1, 0};

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a)  (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 1000000

int check[maxN+5];
vi primes;
int m[maxN+5];
int p[25];

void sieve()
{
    for(int i = 1 ; i <= 1000000 ; i++) check[i] = true;
    
    for(ll i = 2 ; i <= maxN ; i++)
        if(check[i])
        {
            primes.pb(i);
            for(ll j = i ; i * j <= maxN ; j++)
                check[i*j] = false;
        }
}

void preCal()
{
    sieve();
    p[0] = 1;
    fr(i,1,20)
    {
        p[i] = p[i-1] * 2;
        p[i] %= 10;
    }
    
    fr(i,1,maxN) m[i] = 1;
    
    rep(i,sz(primes))
    {
        if(primes[i] == 2 || primes[i] == 5) continue;
        int k = primes[i];
        
        while(k <= maxN)
        {
            m[k] *= primes[i];
            m[k] %= 10;
            if(primes[i] >= 1000) break;
            k *= primes[i];
        }
    }
    
    fr(i,2,maxN)
    {
        m[i] *= m[i-1];
        m[i] %= 10;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10680 - LCM.INP","r",stdin);
    freopen("10680 - LCM.OUT","w",stdout);
    #endif
    
    preCal();
    int n;
    while(read(n) && n)
    {
        int k = log(n);
        int t = log(n)/log(2);
        int f = log(n)/log(5);
        
        t -= f;
        int ans = m[n] * p[t];
        ans %= 10;
        cout << ans << endl;
    }
    
    return 0;
}

