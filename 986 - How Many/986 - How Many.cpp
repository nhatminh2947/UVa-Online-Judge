//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 986 - How Many
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

int n,r,k;
int dp[105][105][105][2];

int solve(int x, int y, int p, int d)
{
    if(x > 2*n || y < 0 || p > r)
    {
        //puts("return 0");
        return 0;
    }
    
    if(x == 2*n && y == 0 && p == r)
    {
        //puts("return 1");
        return 1;
    }
    if(x == 2*n && y == 0)
    {
        //puts("return 0");
        return 0;
    }
    
    if(dp[x][y][p][d] != -1) return dp[x][y][p][d];
    
    //printf("x = %2d y = %2d p = %2d d = %2d --> x = %2d y = %2d p = %2d d = %2d\n",x,y,p,d,x+1,y+1,p,1);
    int ans = solve(x+1,y+1,p,1);
    
    if(d == 1)
    {
        //printf("x = %2d y = %2d p = %2d d = %2d --> x = %2d y = %2d p = %2d d = %2d\n",x,y,p,d,x+1,y-1,p+1,0);
        ans += solve(x+1,y-1,p + (y == k),0);
    }
    else
    {
        //printf("x = %2d y = %2d p = %2d d = %2d --> x = %2d y = %2d p = %2d d = %2d\n",x,y,p,d,x+1,y-1,p,0);
        ans += solve(x+1,y-1,p  ,0);
    }
    
    return dp[x][y][p][d] = ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("986 - How Many.INP","r",stdin);
    freopen("986 - How Many.OUT","w",stdout);
    #endif
    
    while(read3(n,r,k))
    {
        fr(i,0,60) fr(j,0,60) fr(d,0,60) 
            dp[i][j][d][0] = dp[i][j][d][1] = -1;
        
        int ans = solve(0,0,0,1);
        cout << ans << endl;
    }
    
    return 0;
}
