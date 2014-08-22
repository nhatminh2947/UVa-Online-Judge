//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10976 - Fractions Again!
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

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10976 - Fractions Again!.INP","r",stdin);
    freopen("10976 - Fractions Again!.OUT","w",stdout);
    #endif
    
    int k;
    while(read(k))
    {
        //DEBUG(k);
        vii v;
        for(int y = k+1 ; y <= 2*k ; y++)
        {
            int a = y*k;
            int b = y-k;
            
            if(a%b == 0)
            {
                v.pb(mp(a/b,y));
            }
        }
        
        printf("%d\n",sz(v));
        rep(i,sz(v))
            printf("1/%d = 1/%d + 1/%d\n",k,v[i].ff,v[i].ss);
    }
    
    return 0;
}
