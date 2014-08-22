//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11643 - Knight Tour
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

int n,m;
int id[1005][1005];
int step[1005][1005];
int dp[25][140005];
int adj[25][25];

int dx[] = {-2,-2,-1,-1, 1, 1, 2, 2};
int dy[] = {-1, 1,-2, 2,-2, 2,-1, 1};

bool inside(int y, int x)
{
    return (1 <= y && y <= n && 1 <= x && x <= n);
}

void BFS(ii st)
{
    queue<ii> q;
    fr(i,1,n) fr(j,1,n) step[i][j] = -1;
    
    q.push(st);
    step[st.ff][st.ss] = 0;
    
    while(!q.empty())
    {
        ii p = q.front();
        
        int y = p.ff;
        int x = p.ss;
        
        q.pop();
        
        if(id[y][x] != -1 && id[y][x] != id[st.ff][st.ss])
            adj[id[st.ff][st.ss]][id[y][x]] = step[y][x];
        
        rep(i,8)
        {
            int yy = y + dy[i];
            int xx = x + dx[i];
            
            if(inside(yy,xx) && step[yy][xx] == -1)
            {
                q.push(mp(yy,xx));
                step[yy][xx] = step[y][x] + 1;
            }
        }
    }
}

int solve(int st, int p, int stt)
{
    if(stt == ((1<<m)-1)) return 0;
    
    if(dp[p][stt] != -1) return dp[p][stt];
    
    int ans = INF;
    rep(i,m)
    {
        if(i != p)
        {
            int k = (1 << i);
            
            if((stt&k) == 0)
            {
                int d = adj[p][i] + solve(st,i,stt|k);
                if((stt|k) == ((1<<m)-1)) d += adj[i][st];
                ans = min(ans, d);
            }
        }
    }
    
    return dp[p][stt] = ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11643 - Knight Tour.INP","r",stdin);
    freopen("11643 - Knight Tour.OUT","w",stdout);
    #endif
    
    int tcs;
    read(tcs);
    
    fr(t,1,tcs)
    {
        read2(n,m);
        
        fr(i,1,n) fr(j,1,n)
            id[i][j] = -1;
        
        vii v;
        
        rep(i,m)
        {
            rep(j,m) adj[i][j] = -1;
            
            int y,x;
            read2(y,x);
            id[y][x] = i;
            
            v.pb(mp(y,x));
        }
        
        rep(i,sz(v))
            BFS(v[i]);
        
        fr(i,0,m)
            fr(j,0,(1<<m))
                dp[i][j] = -1;
        
        int ans = INF;
        rep(i,m)
            ans = min(ans,solve(i,i,1<<i));
        
        printf("Case %d: %d\n",t,ans);
    }
    
    return 0;
}
