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

ll a, b;

ll luyThua( ll n, int x ){
    if ( x == 1 ) return n;
    ll kq = luyThua(n,x/2);
    kq = kq*kq;
    if ( x%2 ) kq*=n;
    return kq;
}

ll findD( )
{
    if ( b == 1 ) return 1;
    for (ll n=2; n<=b; n++) 
    {
        int x = log10(b)/log10(n);
        if ( luyThua(n,x) == b && luyThua(n+1,x) == a ) return n;
    }
    return -1;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("107.INP","r",stdin);
    freopen("107.OUT","w",stdout);
    #endif
    while ( scanf("%lld %lld",&a,&b) &&a &&b )
    {
        ll n = findD();
        ll kq1 =0, kq2 = 0;
        ll con = 1;
        while ( a>=1 )
        {
            kq2 += con*a;
            if ( a == 1 ) break;
            kq1 += con;
            con *=n;
            a/=(n+1);
        }
        cout << kq1 << " " << kq2 << endl;
    }
    
    
    return 0;
}
