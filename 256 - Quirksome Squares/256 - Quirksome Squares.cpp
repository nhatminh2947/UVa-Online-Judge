//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 256 - Quirksome Squares
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

vi cal[10];
vector<string> ans[10];

void preCal()
{
    int p = 1;
    int d = 1;
    for(int k = 2 ; k <= 8 ; k+=2)
    {
        p *= 100;
        d *= 10;
        for(int i = 0 ; i < p ; i++)
        {
            int a = i%d;
            int b = i/d;
            
            if(sqr(a+b) == i) cal[k].pb(i);
        }
    }
}

void solve()
{
    ans[2].pb("00");
    ans[2].pb("01");
    ans[2].pb("81");
    ans[4].pb("0000");
    ans[4].pb("0001");
    ans[4].pb("2025");
    ans[4].pb("3025");
    ans[4].pb("9801");
    ans[6].pb("000000");
    ans[6].pb("000001");
    ans[6].pb("088209");
    ans[6].pb("494209");
    ans[6].pb("998001");
    ans[8].pb("00000000");
    ans[8].pb("00000001");
    ans[8].pb("04941729");
    ans[8].pb("07441984");
    ans[8].pb("24502500");
    ans[8].pb("25502500");
    ans[8].pb("52881984");
    ans[8].pb("60481729");
    ans[8].pb("99980001");
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("256 - Quirksome Squares.INP","r",stdin);
    freopen("256 - Quirksome Squares.OUT","w",stdout);
    #endif
    
    //preCal();
    solve();
    int n;
    while(read(n))
    {
        rep(i,sz(ans[n]))
            cout << ans[n][i] << endl;
    }
    
    return 0;
}
