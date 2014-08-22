//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11470 - Square Sums
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

int n;
int sum[100];
int a[15][15];
int c[15][15];
int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};

bool inside(int y, int x)
{
    return (1 <= x && x <= n && 1 <= y && y <= n);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11470 - Square Sums.INP","r",stdin);
    freopen("11470 - Square Sums.OUT","w",stdout);
    #endif
    int tcs = 1;
    while(scanf(" %d ",&n) && n)
    {
        fr(i,1,n) fr(j,1,n)
        {
            sum[i] = 0;
            c[i][j] = INF;
            scanf(" %d ",&a[i][j]);
        }
        
        queue<ii> q;
        
        if(n % 2)
        {
            q.push(mp((n+1)/2,(n+1)/2));
            c[(n+1)/2][(n+1)/2] = 1;
        }
        else
        {
            q.push(mp(n/2  ,n/2  ));
            q.push(mp(n/2  ,n/2+1));
            q.push(mp(n/2+1,n/2  ));
            q.push(mp(n/2+1,n/2+1));
            c[n/2  ][n/2  ] = 1;
            c[n/2  ][n/2+1] = 1;
            c[n/2+1][n/2  ] = 1;
            c[n/2+1][n/2+1] = 1;
        }
        
        while(!q.empty())
        {
            int x = q.front().ss;
            int y = q.front().ff;
            
            sum[c[y][x]] += a[y][x];
            q.pop();
            rep(i,8)
            {
                int xx = x + dx[i];
                int yy = y + dy[i];
                
                if(c[yy][xx] == INF)
                {
                    q.push(mp(yy,xx));
                    c[yy][xx] = c[y][x] + 1;
                }
            }
        }
        
        printf("Case %d:",tcs++);
        for(int i = (n+1)/2 ; i >= 1 ; i--)
            printf(" %d",sum[i]);
        printf("\n");
    }
    
    return 0;
}
