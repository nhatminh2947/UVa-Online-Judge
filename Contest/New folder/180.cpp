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

void preCal()
{
    
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("180.INP","r",stdin);
    freopen("180.OUT","w",stdout);
    #endif
    double ma, mb, mc;
    while ( scanf("%lf %lf %lf",&ma,&mb,&mc)!=EOF)
    {
        if ( (ma < mb + mc) && ( mb < ma + mc ) && ( mc < ma + mb ) ){
            ma = 2.0/3.0*ma;
            mb = 2.0/3.0*mb;
            mc = 2.0/3.0*mc;
        //cout << " ma = " << ma << endl;
        
            double p = ( ma + mb + mc )/2.0;
        //cout << " p = " << p << endl;
        
            double kq = 3.0*sqrt(p*(p-ma)*(p-mb)*(p-mc));
            printf("%.3lf\n",kq);
        } else cout << "-1.000" << endl;
    }
    
    
    return 0;
}
