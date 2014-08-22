//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11101 - Mall Mania
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
#define maxN 2000

queue<ii> q;
int a[maxN+5][maxN+5];
int dx[] = {-1, 0, 0, 1};
int dy[] = { 0,-1, 1, 0};

bool inside(int y, int x)
{
    return (0 <= x && x <= 2000 && 0 <= y && y <= 2000);
}

int BFS()
{
    while(!q.empty())
    {
        int y = q.front().ff;
        int x = q.front().ss;
        q.pop();
        
        rep(i,4)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(inside(yy,xx))
            {
                if(a[yy][xx] == INF) return a[y][x] + 1;
                else if(a[yy][xx] == -1)
                {
                    a[yy][xx] = a[y][x] + 1;
                    q.push(mp(yy,xx));
                }
            }
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11101 - Mall Mania.INP","r",stdin);
    freopen("11101 - Mall Mania.OUT","w",stdout);
    #endif
    int n;
    while(scanf(" %d ",&n) && n)
    {
        while(sz(q)) q.pop();
        fr(i,0,maxN) fr(j,0,maxN) a[i][j] = -1;
        rep(i,n)
        {
            int x,y;
            scanf(" %d %d ",&x,&y);
            q.push(mp(y,x));
            a[y][x] = 0;
        }
        
        scanf(" %d ",&n);
        rep(i,n)
        {
            int x,y;
            scanf(" %d %d ",&x,&y);
            a[y][x] = INF;
        }
        
        printf("%d\n",BFS());
    }

    return 0;
}