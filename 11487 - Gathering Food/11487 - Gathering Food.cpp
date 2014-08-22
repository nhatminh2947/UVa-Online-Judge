//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11487 - Gathering Food
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

char a[15][15];
int dist[300][15][15];
int cnt[300][15][15];
int n;

int dx[] = {-1, 0, 0, 1};
int dy[] = { 0,-1, 1, 0};

bool inside(int y, int x)
{
    return 1 <= y && y <= n && 1 <= x && x <= n;
}

int BFS(int sty, int stx, int ed, int edy, int edx)
{
    dist['A'][sty][stx] = 0;
    cnt['A'][sty][stx] = 1;
    queue< pair<ii,ii> > q;
    
    q.push(mp(mp('A',0),mp(sty,stx)));
    
    while(!q.empty())
    {
        int c = q.front().ff.ff;
        int d = q.front().ff.ss;
        int yy = q.front().ss.ff;
        int xx = q.front().ss.ss;
        
        if(c == ed && yy == edy && xx == edx)
            return dist[c][yy][xx];
        
        q.pop();
        
        rep(i,4)
        {
            int yyy = yy + dy[i];
            int xxx = xx + dx[i];
            
            if(inside(yyy,xxx) && a[yyy][xxx] != '#')
            {
                int ch = a[yyy][xxx] == '.' ? c : a[yyy][xxx];
                
                //printf("c = %c y = %3d x = %3d ---> ch = %c yy = %3d xx = %3d\n",c,yy,xx,ch,yyy,xxx);
                if((a[yyy][xxx] == '.' || a[yyy][xxx] == c + 1))
                {
                    if(dist[ch][yyy][xxx] == -1)
                    {
                        dist[ch][yyy][xxx] = dist[c][yy][xx] + 1;
                        q.push(mp(mp(ch,i),mp(yyy,xxx)));
                    }
                    
                    cnt[ch][yyy][xxx] += cnt[c][yy][xx]%20437;
                    cnt[ch][yyy][xxx] %=20437;
                }
                else if(c > a[yyy][xxx])
                {
                    if(dist[c][yyy][xxx] == -1)
                    {
                        dist[c][yyy][xxx] = dist[c][yy][xx] + 1;
                        q.push(mp(mp(c,i),mp(yyy,xxx)));
                    }
                    cnt[c][yyy][xxx] += cnt[c][yy][xx]%20437;
                    cnt[c][yyy][xxx] %=20437;
                }
                
                //printf("%d\n",cnt[ch][yyy][xxx]);
            }
        }
    }
    
    return -1;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11487 - Gathering Food.INP","r",stdin);
    freopen("11487 - Gathering Food.OUT","w",stdout);
    #endif
    int tcs = 1;
    while(scanf(" %d ",&n) && n)
    {
        int ed = -INF;
        int edx, edy, stx, sty;
        fr(i,1,n)
        {
            gets(a[i]+1);
            fr(j,1,n)
                if('A' <= a[i][j] && a[i][j] <= 'Z')
                {
                    if(ed < a[i][j])
                    {
                        ed = a[i][j];
                        edy = i;
                        edx = j;
                    }
                    if(a[i][j] == 'A')
                    {
                        sty = i;
                        stx = j;
                    }
                }
        }
        
        fr(k,'A','Z') fr(i,1,n) fr(j,1,n)
        {
            dist[k][i][j] = -1;
            //fr(d,0,4)
            cnt[k][i][j] = 0;
        }
        
        printf("Case %d: ",tcs++);
        if(BFS(sty,stx,ed,edy,edx) == -1) puts("Impossible");
        else printf("%d %d\n",dist[ed][edy][edx], cnt[ed][edy][edx]);
    }
    
    return 0;
}
