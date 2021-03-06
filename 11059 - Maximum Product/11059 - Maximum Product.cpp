//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11059 - Maximum Product
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
#define maxN 100000

ll a[100];
int n;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11059 - Maximum Product.INP","r",stdin);
    freopen("11059 - Maximum Product.OUT","w",stdout);
    #endif
    int tcs = 1;
    while(scanf(" %d ",&n) == 1)
    {
        rep(i,n) read(a[i]);
        
        ll ans = 0;
        fr(i,0,n-1)
            fr(j,i,n-1)
            {
                ll m = 1;
                fr(k,i,j)
                {
                    m *= a[k];
                }
                //printf("i = %3d j = %3d     m = %3d\n",i,j,m);
                ans = max(ans,m);
            }
        
        
        cout << "Case #" << tcs++ << ": The maximum product is " << ans << "." << endl << endl;
    }
    
    return 0;
}
