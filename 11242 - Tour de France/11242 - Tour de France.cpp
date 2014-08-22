//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11242 - Tour de France
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
#define out(x) cout << x << endl
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

int f,r;
double a[105],b[105];
vector<double> v;

int main()
{
    freopen("11242 - Tour de France.INP","r",stdin);
    freopen("11242 - Tour de France.OUT","w",stdout);

    while(read(f) && f)
    {
        v.clear();
        //DEBUG(f);
        read(r);
        rep(i,f) read(a[i]);
        rep(i,r) read(b[i]);
        
        rep(i,r) rep(j,f) v.pb(b[i]/a[j]);
        
        sort(all(v));
        
        double ans = -INF;
        rep(i,sz(v)-1)
            ans = max(ans,v[i+1]/v[i]);
        
        printf("%.2lf\n",ans);
    }

    return 0;
}