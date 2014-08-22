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

ll a[100][100];
ll dist[100][100][10][10];
int n,k;
bool vis[100][100];
bool check;

int dx[] = {-1, 0, 1};
int dy[] = { 0, 1, 0};

bool inside(int y, int x)
{
    return (1 <= x && x <= n && 1 <= y && y <= n);
}

ll DFS(int y, int x, int cnt, int d)
{
    if(cnt > k) return -INF*100LL;
    
    if(dist[y][x][cnt][d] != -INF) return dist[y][x][cnt][d];
    
    if(y == n && x == n)
    {
        check = true;
        return dist[y][x][cnt][d] = a[y][x];
    }
    
    ll ans = -INF*100LL;
    rep(i,3)
    {
        int yy = y + dy[i];
        int xx = x + dx[i];
        
        if(inside(yy,xx) && !vis[yy][xx])
        {
            vis[yy][xx] = true;
            
            ll kq = DFS(yy,xx,cnt+(a[yy][xx] < 0), i);
            if(kq != -INF*100LL)
                ans = max(ans, kq + a[y][x]);
            
            vis[yy][xx] = false;
        }
    }
    
    return dist[y][x][cnt][d] = ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("I.INP","r",stdin);
    freopen("I.OUT","w",stdout);
    #endif
    int tcs = 1;
    while(scanf(" %d %d ",&n,&k) && n)
    {
        fr(i,1,n) fr(j,1,n) read(a[i][j]);
        
        fr(i,1,n) fr(j,1,n)
        {
            vis[i][j] = false;
            fr(u,0,5) fr(v,0,5) dist[i][j][u][v] = -INF;
        }
        
        vis[1][1] = true;
        check = false;
        ll ans = DFS(1,1,(a[1][1]<0),0);
        
        printf("Case %d: ",tcs++);
        if(check) printf("%lld\n",ans);
        else puts("impossible");
    }
    
    return 0;
}
