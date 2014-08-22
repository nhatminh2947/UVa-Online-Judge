//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 314 - Robot
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

int dx[] = {-1, 0, 1, 0};
int dy[] = { 0,-1, 0, 1};
int dir[300];

int a[505][505];
int dist[10][505][505];
int n,m;
ii st,ed;
string d;

bool inside(int y, int x)
{
    return (1 < y && y < 2*n-1 && 0 < x && x < 2*m-1);
}

int BFS()
{
    rep(k,10)
        rep(i,500)
            rep(j,500)
                dist[k][i][j] = INF;
    
    queue< pair<int, ii> > q;
    q.push(mp(dir[d[0]],mp(st.ff,st.ss)));
    dist[dir[d[0]]][st.ff][st.ss] = 0;
    //cout << "BBB" << endl;
    while(!q.empty())
    {
        int y = q.front().ss.ff;
        int x = q.front().ss.ss;
        int h = q.front().ff;
        
        q.pop();
        if(y == ed.ff && x == ed.ss)
            return dist[h][y][x];
        
        for(int i = 2 ; i <= 6 ; i += 2)
        {
            int yy = y + i*dy[h];
            int xx = x + i*dx[h];
            //DEBUG(yy);
            //DEBUG(xx);
            if(inside(yy,xx) && a[yy][xx] && dist[h][yy][xx] == INF)
            {
                q.push(mp(h,mp(yy,xx)));
                dist[h][yy][xx] = dist[h][y][x] + 1;
                //printf("x = %3d y = %3d h = %3d ---> xx = %3d yy = %3d h = %3d  ==  dist[%d][%d][%d] = %3d\n",x,y,h,xx,yy,h,h,y,x,dist[h][yy][xx]);
            }
            else break;
        }
        
        //right
        
        int r = (h+1)%4;
        if(dist[r][y][x] == INF)
        {
            q.push(mp(r,mp(y,x)));
            dist[r][y][x] = dist[h][y][x] + 1;
            //printf("x = %3d y = %3d h = %3d --->  x = %3d  y = %3d h = %3d  ==  dist[%d][%d][%d] = %3d\n",x,y,h,x,y,r,r,y,x,dist[r][y][x]);
        }
        //left
        
        int l = (r+2)%4;
        if(dist[l][y][x] == INF)
        {
            q.push(mp(l,mp(y,x)));
            dist[l][y][x] = dist[h][y][x] + 1;
            //printf("x = %3d y = %3d h = %3d --->  x = %3d  y = %3d h = %3d  ==  dist[%d][%d][%d] = %3d\n",x,y,h,x,y,l,l,y,x,dist[l][y][x]);
        }
        //cout << "=========================================" << endl;
    }
    
    return -1;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("314 - Robot.INP","r",stdin);
    freopen("314 - Robot.OUT","w",stdout);
    #endif
    
    dir['w'] = 0;
    dir['n'] = 1;
    dir['e'] = 2;
    dir['s'] = 3;
    
    while(scanf(" %d %d ",&n,&m) && (n+m))
    {
        fr(i,0,500) fr(j,0,500)
            a[i][j] = 1;
        
        rep(i,n)
            rep(j,m)
            {
                int k;
                scanf(" %d ",&k);
                
                int y = 2*i + 1;
                int x = 2*j + 1;
                
                a[y][x] = 0;
                
                if(k)
                {
                    fr(u,-1,1) fr(v,-1,1)
                        a[y+u][x+v] = 0;
                }
            }
        
        read2(st.ff,st.ss);
        read2(ed.ff,ed.ss);
        read(d);
        
        if(st.ff == ed.ff && st.ss == ed.ss)
        {
            puts("0");
            continue;
        }
        
        st.ff *= 2;
        st.ss *= 2;
        ed.ff *= 2;
        ed.ss *= 2;
            
        /*fr(i,0,2*n)
        {
            //DEBUG(i);
            fr(j,0,2*m)
            {
                if(a[i][j] == 0) printf("X");
                else printf("O");
            }
            printf("\n");
        }
        cout << "AAA" << endl;*/
        cout << BFS() << endl;
    }
    
    return 0;
}
