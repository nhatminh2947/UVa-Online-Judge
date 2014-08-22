//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10047 - The Monocycle
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

int dx[] = { 0, 1, 0,-1};
int dy[] = {-1, 0, 1, 0};

struct pos
{
    int x,y,d,c;
    pos(){};
    pos(int Y, int X, int D, int C)
    {
        x = X;
        y = Y;
        d = D;
        c = C;
    }
    
    pos turnLeft()
    {
        return pos(y,x,(d+3)%4,c);
    }
    
    pos turnRight()
    {
        return pos(y,x,(d+1)%4,c);
    }
    
    pos fw()
    {
        return pos(y + dy[d],x + dx[d],d,(c+1)%5);
    }
    
    bool eq(pos p)
    {
        return (p.x == x && p.y == y && p.c == c);
    }
    
    bool inside(int n, int m)
    {
        return (0 <= x && x < m && 0 <= y && y < n);
    }
    
    void print()
    {
        printf("x = %d\ny = %d\nd = %d\nc = %d\n",x,y,d,c);
    }
};

int n,m;
char g[30][30];
int step[30][30][10][10];
pos S,T;

int BFS()
{
    queue<pos> q;
    q.push(S);
    step[S.y][S.x][S.d][S.c] = 0;
    
    while(!q.empty())
    {
        pos p = q.front();
        q.pop();
        
        if(p.eq(T)) return step[p.y][p.x][p.d][p.c];
            
        pos tmp;
        tmp = p.turnLeft();
        if(step[tmp.y][tmp.x][tmp.d][tmp.c] == -1)
        {
            step[tmp.y][tmp.x][tmp.d][tmp.c] = step[p.y][p.x][p.d][p.c] + 1;
            q.push(tmp);
        }
        
        tmp = p.turnRight();
        if(step[tmp.y][tmp.x][tmp.d][tmp.c] == -1)
        {
            step[tmp.y][tmp.x][tmp.d][tmp.c] = step[p.y][p.x][p.d][p.c] + 1;
            q.push(tmp);
        }
        
        tmp = p.fw();
        if(tmp.inside(n,m) && g[tmp.y][tmp.x] != '#' && step[tmp.y][tmp.x][tmp.d][tmp.c] == -1)
        {
            step[tmp.y][tmp.x][tmp.d][tmp.c] = step[p.y][p.x][p.d][p.c] + 1;
            q.push(tmp);
        }
    }
    
    return -1;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10047 - The Monocycle.INP","r",stdin);
    freopen("10047 - The Monocycle.OUT","w",stdout);
    #endif
    
    int tcs = 0;
    while(scanf(" %d %d ",&n,&m) && n)
    {
        rep(i,n)
        {
            gets(g[i]);
            rep(j,m)
            {
                if(g[i][j] == 'S') S = pos(i,j,0,0);
                if(g[i][j] == 'T') T = pos(i,j,0,0);
                rep(k,10) rep(l,10) step[i][j][k][l] = -1;
            }
        }
        
        if(tcs) printf("\n");
        printf("Case #%d\n",++tcs);
        int ans = BFS();
        if(ans != -1) printf("minimum time = %d sec\n",ans);
        else puts("destination not reachable");
    }

    return 0;
}