//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10827 - Maximum sum on a torus
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

int n;
int a[80][80];
int r[80][80];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10827 - Maximum sum on a torus.INP","r",stdin);
    freopen("10827 - Maximum sum on a torus.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    
    fr(t,1,tcs)
    {
        scanf(" %d ",&n);
        fr(i,1,n) fr(j,1,n) scanf(" %d ",&a[i][j]);
        
        fr(i,1,n)
        {
            r[i][0] = 0;
            fr(j,1,n) r[i][j] = r[i][j-1] + a[i][j];
        }
        
        int ans = -INF;
        fr(up,1,n)
            fr(lf,1,n)
                fr(rg,1,n)
                {
                    int sum = 0;
                    fr(dw,up,n)
                    {
                        sum += (r[dw][rg] - r[dw][lf-1]);
                        ans = max(ans,sum);
                    }
                }
                
        printf("%d\n",ans);
    }
    
    return 0;
}
