//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11428 - Cubes
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

bool ok[10005];
ll x[10005],y[10005];

void preCal()
{
    fr(i,0,10000) ok[i] = false;
    
    for(ll yy = 0 ; yy <= 60 ; yy++)
        for(ll xx = 0 ; xx <= 60 ; xx++)
        {
            ll k = xx*xx*xx - yy*yy*yy;
            if(0 <= k && k <= 10000 && !ok[k])
            {
                x[k] = xx;
                y[k] = yy;
                ok[k] = true;
            }
        }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11428 - Cubes.INP","r",stdin);
    freopen("11428 - Cubes.OUT","w",stdout);
    #endif
    
    //fr(i,1,10000) printf("%d\n",i);
    
    int n;
    preCal();
    while(scanf("%d",&n) && n)
    {
        if(ok[n])
        {
            cout << x[n] << " " << y[n] << endl;
        }
        else puts("No solution");
    }

    return 0;
}