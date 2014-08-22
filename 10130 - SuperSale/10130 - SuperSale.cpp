//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10130 - SuperSale
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
#define maxN 1000

int p[maxN+5], w[maxN+5];
int dp[maxN+5][35];
int n;

int solve(int k, int sum)
{
    if(sum < 0) return -INF;
    if(k == 0) return dp[k][sum] = 0;
    if(dp[k][sum]) return dp[k][sum];
    
    return dp[k][sum] = max(solve(k-1,sum), p[k] + solve(k-1,sum - w[k]));
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10130 - SuperSale.INP","r",stdin);
    freopen("10130 - SuperSale.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    
    fr(t,1,tcs)
    {
        scanf(" %d ",&n);
        //DEBUG(n);
        fr(i,1,n) scanf(" %d %d ",&p[i],&w[i]);
        
        fr(i,0,n) fr(j,0,30) dp[i][j] = 0;
        
        fr(i,1,n)
        {
            fr(j,1,30)
            {
                dp[i][j] = dp[i-1][j];
                if(j - w[i] >= 0)
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + p[i]);
                //printf("%3d",dp[i][j]);
            }
            //printf("\n");
        }
        int g;
        scanf(" %d ",&g);
        //DEBUG(g);
        int ans = 0;
        rep(i,g)
        {
            int m;
            scanf(" %d ",&m);
            ans += dp[n][m];
            //DEBUG(dp[n][m]);
            //DEBUG(solve(n,m));
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
