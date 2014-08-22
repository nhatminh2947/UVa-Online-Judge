//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11906 - Knight in a War Grid
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

bool vis[105][105];
int step[105][105];
int r,c,m,n,w;
int dx[10];
int dy[10];

bool inside(int y, int x)
{
    return (0 <= x && x < c && 0 <= y && y < r);
}

void DFS(int y, int x)
{
    int st = 0;
    int ed = 8;
    
    if(m == n) ed = 4;
    else if(m == 0 || n == 0)
    {
        st = 2;
        ed = 6;
    }
    
    for(int i = st ; i < ed ; i++)
    {
        int yy = y + dy[i];
        int xx = x + dx[i];
        if(inside(yy,xx) && step[yy][xx] != -1)
        {
            step[yy][xx]++;
            if(!vis[yy][xx])
            {
                vis[yy][xx] = true;
                DFS(yy,xx);
            }
        }
    }
}

void reset()
{
    dx[0] = -m;     dy[0] = n;
    dx[1] = m;      dy[1] = -n;
    dx[2] = -m;     dy[2] = -n;
    dx[3] = m;      dy[3] = n;
    dx[4] = n;      dy[4] = -m;
    dx[5] = -n;     dy[5] = m;
    dx[6] = -n;     dy[6] = -m;
    dx[7] = n;      dy[7] = m;
    
    rep(i,r) rep(j,c)
    {
        vis[i][j] = false;
        step[i][j] = 0;
    }
    
    vis[0][0] = true;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11906 - Knight in a War Grid.INP","r",stdin);
    freopen("11906 - Knight in a War Grid.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    
    fr(t,1,tcs)
    {
        scanf(" %d %d %d %d ",&r,&c,&m,&n);
        
        scanf(" %d ",&w);
        
        reset();
        
        rep(i,w)
        {
            int x,y;
            scanf(" %d %d ",&y,&x);
            step[y][x] = -1;
        }
        
        DFS(0,0);
        
        int even = 0;
        int odd = 0;
        
        rep(i,r) rep(j,c)
            if(vis[i][j])
            {
                if(step[i][j] % 2 == 0) even++;
                else odd++;
            }
        
        printf("Case %d: %d %d\n",t,even,odd);
    }
    
    return 0;
}