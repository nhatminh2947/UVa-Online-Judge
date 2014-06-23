//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 357 - Let Me Count The Ways
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

int coin[] = {1,5,10,25,50};
ll dp[10][30005];

ll solve(int k, int sum)
{
    if(sum < 0) return 0;
    if(coin[k] == 1) return dp[k][sum] = 1;
    if(dp[k][sum] != -1) return dp[k][sum];
    //printf("k = %d sum = %d\n",k,sum);
    ll ans = 0;
    
    for(int i = 0 ; coin[k]*i <= sum ; i++)
        ans += solve(k-1,sum - coin[k]*i);
    
    return dp[k][sum] = ans;
}

void preCal()
{
    for(int i = 0 ; i < 5 ; i++)
        for(int j = 0 ; j <= 30000 ; j++)
            dp[i][j] = -1;
    
    for(int i = 30000 ; i >= 0 ; i--)
        solve(4,i);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("357 - Let Me Count The Ways.INP","r",stdin);
    freopen("357 - Let Me Count The Ways.OUT","w",stdout);
    #endif
    
    int n;
    preCal();
    while(read(n))
    {
        if(dp[4][n] == 1) printf("There is only 1 way to produce %d cents change.\n",n);
        else printf("There are %lld ways to produce %d cents change.\n",dp[4][n],n);
    }
    
    return 0;
}
