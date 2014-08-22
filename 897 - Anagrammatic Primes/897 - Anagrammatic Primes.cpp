//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 897 - Anagrammatic Primes
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
#define maxN 10000000

int ans[maxN+5];
bool check[maxN+5];
vi primes, a;

void sieve()
{
    for(int i = 0 ; i <= maxN ; i++)
        check[i] = true;
    
    for(ll i = 2 ; i <= maxN ; i++)
    {
        if(check[i])
        {
            primes.pb(i);
            for(ll j = i ; i*j <= maxN ; j++)
                check[i*j] = false;
        }
    }
    a.pb(2);
    rep(i,sz(primes))
    {
        int k = primes[i];
        bool ok = true;
        while(k)
        {
            if(k%10 == 0 || (k%10)%2 == 0)
            {
                ok = false;
                break;
            }
            k /= 10;
        }
        
        if(ok) a.pb(primes[i]);
    }
    //DEBUG(sz(a));
    
    //DEBUG(a[sz(a)-1]);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("897 - Anagrammatic Primes.INP","r",stdin);
    freopen("897 - Anagrammatic Primes.OUT","w",stdout);
    #endif
    
    sieve();
    
    int n;
    while(read(n) && n)
    {
        int ans = 0;
        int p = 1;
        while(p <= n) p *= 10;
        //DEBUG(p);
        int t = 0;
        while(a[t] <= n) t++;
        
        for(int i = t ; i < sz(a) && a[i] < p ; i++)
        {
            //DEBUG(a[i]);
            vi v;
            int m = a[i];
            while(m)
            {
                v.pb(m%10);
                m /= 10;
            }
            
            sort(all(v));
            
            bool tmp = true;
            do
            {
                m = 0;
                rep(k,sz(v)) m = m*10 + v[k];
                if(!check[m]) tmp = false;
                //DEBUG(m);
            }while(next_permutation(all(v)));
            
            if(tmp)
            {
                ans = a[i];
                break;
            }
        }
        
        cout << ans << endl;
    }
    
    return 0;
}
