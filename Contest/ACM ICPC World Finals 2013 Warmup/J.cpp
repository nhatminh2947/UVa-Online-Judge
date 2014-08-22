//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 
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

int n;
int a[1000000+5];
bool check[maxN+5];
vector<int> primes;

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
            //DEBUG(i);
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("J.INP","r",stdin);
    freopen("J.OUT","w",stdout);
    #endif
    //sieve();
    int tcs;
    read(tcs);
    
    fr(t,1,tcs)
    {
        int n;
        read(n);
        //DEBUG(n);
        rep(i,(n*(n-1))/2) read(a[i]);
        sort(a,a+(n*(n-1))/2);
        printf("Case %d:",t);
        
        int k = a[0];
        for(int i = 2 ; i <= (int)sqrt(1e9)+10 ; i++)
            if(a[0] % i == 0)
            {
                k = i;
                break;
            }
        
        vector<int> v;
        v.pb(k);
        //printf(" %d",k);
        rep(i,n-1)
        {
            //printf(" %d",a[i]/k);
            v.pb(a[i]/k);
        }
        
        sort(all(v));
        
        rep(i,sz(v)) printf(" %d",v[i]);
        
        printf("\n");
    }
    
    
    return 0;
}
