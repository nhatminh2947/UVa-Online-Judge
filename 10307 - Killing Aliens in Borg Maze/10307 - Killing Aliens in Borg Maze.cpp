//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10307 - Killing Aliens in Borg Maze
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

int dist[55][55];
char a[55][55];
int n,m;

int dx[] = {-1, 0, 0, 1};
int dy[] = { 0,-1, 1, 0};

vii edge;
int len[5005][5005];
int pSet[5005];

void BFS(int y, int x)
{
    fr(i,1,n)
        fr(j,1,n)
            dist[i][j] = INF;
    
    queue<ii> q;
    q.push(mp(y,x));
    dist[y][x] = 0;
    
    int p = 50*(y-1) + x;
    
    while(!q.empty())
    {
        int yy = q.front().ff;
        int xx = q.front().ss;
        q.pop();
        
        if(a[yy][xx] == 'A' || a[yy][xx] == 'S')
        {
            int k = 50*(yy-1) + xx;
            len[p][k] = dist[yy][xx];
            edge.pb(mp(p,k));
        }
        
        rep(i,4)
        {
            int xxx = xx + dx[i];
            int yyy = yy + dy[i];
            
            if(dist[yyy][xxx] == INF && a[yyy][xxx] != '#')
            {
                dist[yyy][xxx] = dist[yy][xx] + 1;
                q.push(mp(yyy,xxx));
            }
        }
    }
}

void init()
{
    edge.clear();
    fr(i,0,5000) pSet[i] = i;
}

int findSet(int u)
{
    if(pSet[u] == u) return u;
    return pSet[u] = findSet(pSet[u]);
}

void unionSet(int u, int v)
{
    pSet[findSet(u)] = findSet(v);
}

bool cmp(ii u, ii v)
{
    return len[u.ff][u.ss] < len[v.ff][v.ss];
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10307 - Killing Aliens in Borg Maze.INP","r",stdin);
    freopen("10307 - Killing Aliens in Borg Maze.OUT","w",stdout);
    #endif
    
    int tcs;
    read(tcs);
    
    fr(t,1,tcs)
    {
        init();
        
        read2(m,n);
        getchar();
        
        fr(i,1,n)
        {
            gets(a[i]+1);
            //puts(a[i]+1);
        }
        int sl = 0;
        fr(i,1,n)
            fr(j,1,m)
            {
                if(a[i][j] == 'S' || a[i][j] == 'A')
                {
                    sl++;
                    BFS(i,j);
                }
            }
        //DEBUG(sl);
        int ans = 0;
        sort(all(edge),cmp);
        int done = 0;
        
        rep(i,sz(edge))
        {
            //DEBUG(i);
            int u = edge[i].ff;
            int v = edge[i].ss;
            
            int fu = findSet(u);
            int fv = findSet(v);
            
            if(fu != fv)
            {
                unionSet(u,v);
                ans += len[u][v];
                done++;
            }
            //cout << "AAA" << endl;
            if(done == sl-1)
                break;
            //cout << "AAA" << endl;
        }
        
        cout << ans << endl;
    }
    
    return 0;
}
