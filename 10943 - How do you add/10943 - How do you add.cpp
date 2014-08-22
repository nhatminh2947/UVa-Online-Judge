//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10943 - How do you add?
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
#define mod 1000000

int dp[105][105];
int n,m;

int solve(int i, int sum)
{
    if(sum < 0) return 0;
    if(i == m+1)
    {
        if(sum == 0) return 1;
        return 0;
    }
    
    if(dp[i][sum] != -1) return dp[i][sum];
    
    int ans = 0;
    for(int k = 0 ; k <= n ; k++)
    {
        ans += solve(i+1,sum-k)%mod;
        ans %= mod;
    }
    
    return dp[i][sum] = ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10943 - How do you add.INP","r",stdin);
    freopen("10943 - How do you add.OUT","w",stdout);
    #endif
    
    while(read2(n,m) && n)
    {
        fr(i,0,m) fr(j,0,n) dp[i][j] = -1;
        
        printf("%d\n",solve(1,n)%mod);
    }
    
    return 0;
}
