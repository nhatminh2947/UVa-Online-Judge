//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10721 - Bar Codes
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

ll dp[55][55][55];
int n,m,k;

ll solve(int a, int b, int c)
{
    if(b > k || c > m) return 0;
    
    if(dp[a][b][c] != -1) return dp[a][b][c];
    
    if(a == n && b == k) return 1;
    
    return dp[a][b][c] = solve(a+1, b, c+1) + solve(a+1, b+1, 1);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10721 - Bar Codes.INP","r",stdin);
    freopen("10721 - Bar Codes.OUT","w",stdout);
    #endif
    
    while(read3(n,k,m))
    {
        fr(i,0,n)
            fr(j,0,k)
                fr(l,0,m)
                    dp[i][j][l] = -1;
                    
        cout << solve(1,1,1) << endl;
    }
    
    return 0;
}
