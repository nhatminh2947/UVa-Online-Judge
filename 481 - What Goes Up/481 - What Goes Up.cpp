//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 481 - What Goes Up
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

int a[1000005];
int n;
int dp[1000005];
vi v;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("481 - What Goes Up.INP","r",stdin);
    freopen("481 - What Goes Up.OUT","w",stdout);
    #endif
    
    n = 0;
    while(scanf(" %d ",&a[++n]) == 1);
    n--;
    
    vi::iterator it;
    int LIS = 0;
    
    for(int i = 1 ; i <= n ; i++)
    {
        it = lower_bound(all(v),a[i]);
        dp[i] = (int)(it-v.begin());
        
        LIS = max(LIS,dp[i]);
        
        if(it == v.end())
            v.pb(a[i]);
        else *it = a[i];
    }
    
    //DEBUG(LIS);
    vi ans;
    for(int i = n ; i >= 1 ; i--)
    {
        //DEBUG(dp[i]);
        if(dp[i] == LIS)
        {
            LIS--;
            ans.pb(a[i]);
        }
    }
    printf("%d\n-\n",sz(ans));
    for(int i = sz(ans)-1 ; i >= 0 ; i--)
        printf("%d\n",ans[i]);
    
    return 0;
}
