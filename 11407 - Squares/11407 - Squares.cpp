//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11407 - Squares
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
#define maxN 10000

int n;
int dp[maxN+5];

void preCal()
{
    fill(dp,dp+maxN+1,INF);
    
    dp[0] = 0;
    for(int i = 1 ; i <= 100 ; i++)
        dp[i*i] = 1;
    
    for(int i = 1 ; i <= maxN ; i++)
        for(int j = 1 ; j <= sqrt(i) ; j++)
            dp[i] = min(dp[i], dp[j*j] + dp[i - j*j]);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11407 - Squares.INP","r",stdin);
    freopen("11407 - Squares.OUT","w",stdout);
    #endif
    
    preCal();
    
    int tcs;
    read(tcs);
    fr(t,1,tcs)
    {
        read(n);
        printf("%d\n",dp[n]);
    }
    
    return 0;
}
