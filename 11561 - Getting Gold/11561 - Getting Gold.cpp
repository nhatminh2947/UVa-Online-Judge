//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11561 - Getting Gold
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

int n,m;
bool vis[1005][1005];
char a[1005][1005];

int dx[] = {-1, 0, 0, 1};
int dy[] = { 0,-1, 1, 0};

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11561 - Getting Gold.INP","r",stdin);
    freopen("11561 - Getting Gold.OUT","w",stdout);
    #endif
    
    while(read2(m,n))
    {
        getchar();
        
        queue<ii> q;
        
        fr(i,1,n)
        {
            gets(a[i]+1);
            
            fr(j,1,m)
            {
                vis[i][j] = false;
                if(a[i][j] == 'P')
                {
                    vis[i][j] = true;
                    q.push(mp(i,j));
                }
                
                if(a[i][j] == '#' || a[i][j] == 'T') vis[i][j] = true;
            }
        }
        
        int cnt = 0;
        
        while(!q.empty())
        {
            ii p = q.front();
            
            int y = p.ff;
            int x = p.ss;
            
            cnt += (a[y][x] == 'G');
            
            q.pop();
            
            bool ok = true;
            rep(i,4)
            {
                int yy = y + dy[i];
                int xx = x + dx[i];
                
                if(a[yy][xx] == 'T')
                    ok = false;
            }
            
            if(!ok) continue;
            
            rep(i,4)
            {
                int yy = y + dy[i];
                int xx = x + dx[i];
                
                if(!vis[yy][xx])
                {
                    vis[yy][xx] = true;
                    q.push(mp(yy,xx));
                }
            }
        }
        
        cout << cnt << endl;
    }
    
    return 0;
}
