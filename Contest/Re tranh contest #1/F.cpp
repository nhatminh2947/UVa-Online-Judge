//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 
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
#define maxN 100000

int dp[10005][10005];
int n,p,total;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("F.INP","r",stdin);
    freopen("F.OUT","w",stdout);
    #endif
    int tcs = 1;
    while(read2(n,total) && n)
    {
        fr(i,1,total) fr(j,1,total) dp[i][j] = 0;
        
        fr(i,p,total) dp[1][i] = 1;
        
        fr(i,2,n)
        {
            fr(j,1,total)
            {
                fr(k,1,total)
                    if(j <= k && k+j <= total && dp[i-1][j]) dp[i][k+j] += dp[i-1][j];
            }
        }
        
        cout << "Case " << tcs++ << ": " << dp[n][total] << endl;
    }
    
    return 0;
}
