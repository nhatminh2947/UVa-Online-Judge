//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11286 - Conformity
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

map<string,int> m;
string conformity[10005];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11286 - Conformity.INP","r",stdin);
    freopen("11286 - Conformity.OUT","w",stdout);
    #endif
    
    int n;
    while(scanf("%d",&n) && n)
    {
        m.clear();
        int p = -INF;
        rep(i,n)
        {
            vector<string> v;
            rep(j,5)
            {
                string s;
                read(s);
                v.pb(s);
            }
            sort(all(v));
            conformity[i] = "";
            rep(j,5) conformity[i] += v[j];
            //DEBUG(conformity[i]);
            m[conformity[i]]++;
            p = max(p,m[conformity[i]]);
        }
        //DEBUG(p);
        int ans = 0;
        
        rep(i,n) if(m[conformity[i]] == p) ans++;
            
        cout << ans << endl;
    }
    
    return 0;
}
