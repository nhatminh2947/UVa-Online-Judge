//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 847 - A Multiplication Game
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

map< pair<ll,int>, int> m;
ll n;
int solve(ll val, int p)
{
    //printf("val = %lld p = %d\n",val,p);
    if(val >= n)
    {
        return p;
    }
    if(m.count(mp(val,p))) return m[mp(val,p)];
    
    int ans;
    if(p == 0) ans = 0;
    else ans = 1;
    for(int i = 2 ; i <= 9 ; i++)
    {
        if(p == 0) ans = max(ans,solve(val*i,1-p));
        else ans = min(ans,solve(val*i,1-p));
    }
    
    return m[mp(val,p)] = ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("847 - A Multiplication Game.INP","r",stdin);
    freopen("847 - A Multiplication Game.OUT","w",stdout);
    #endif
    
    while(scanf(" %lld ",&n) == 1)
    {
        m.clear();
        if(solve(1,0)) puts("Stan wins.");
        else puts("Ollie wins.");
    }
    
    return 0;
}
