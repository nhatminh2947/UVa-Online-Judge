//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10285 - Longest Run on a Snowboard
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
#define maxN 100000

int r,c;
int a[105][105];
int dp[105][105];

int dx[] = {-1, 0, 0, 1};
int dy[] = { 0,-1, 1, 0};

bool inside(int y, int x)
{
    return (1 <= x && x <= c && 1 <= y && y <= r);
}

int DFS(int y, int x)
{
    if(dp[y][x]) return dp[y][x];
    
    bool check = false;
    rep(i,4)
    {
        int yy = y + dy[i];
        int xx = x + dx[i];
        
        if(inside(yy,xx) && a[y][x] < a[yy][xx])
        {
            check = true;
            dp[y][x] = max(dp[y][x],DFS(yy,xx)+1);
        }
    }
    
    if(!check) return dp[y][x] = 1;
    
    return dp[y][x];
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10285 - Longest Run on a Snowboard.INP","r",stdin);
    freopen("10285 - Longest Run on a Snowboard.OUT","w",stdout);
    #endif
    
    int tcs;
    
    scanf(" %d ",&tcs);
    
    rep(t,tcs)
    {
        char name[1000];
        scanf(" %s %d %d ",&name,&r,&c);
        
        fr(i,1,r) fr(j,1,c)
        {
            scanf(" %d ",&a[i][j]);
            dp[i][j] = 0;
        }
        
        int ans = 0;
        fr(i,1,r) fr(j,1,c) ans = max(ans,DFS(i,j));
        
        printf("%s: %d\n",name,ans);
    }
    
    return 0;
}