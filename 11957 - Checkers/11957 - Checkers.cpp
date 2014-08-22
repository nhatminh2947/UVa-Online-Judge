//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11957 - Checkers
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

char a[105][105];
int step[105][105];
int n;

bool inside(int y, int x)
{
    return (0 <= x && x < n && 0 <= y && y < n);
}

int DFS(int y, int x)
{
    //DEBUG(y);
    //DEBUG(x);
    if(!inside(y,x)) return 0;
    
    if(step[y][x]) return step[y][x];
    
    if(y == 0) return step[y][x] = 1;
    if(y < 0) return 0;
    
    int u,v;
    
    if(a[y-1][x+1] == 'B')
    {
        if(inside(y-2,x+2) && a[y-2][x+2] == 'B') u = 0;
        else u = DFS(y-2,x+2);
    }
    else u = DFS(y-1,x+1);
    
    if(a[y-1][x-1] == 'B')
    {
        if(inside(y-2,x-2) && a[y-2][x-2] == 'B') v = 0;
        else v = DFS(y-2,x-2);
    }
    else v = DFS(y-1,x-1);
    
    step[y][x] += (u%1000007+v%1000007)%1000007;
    
    return step[y][x];
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11957 - Checkers.INP","r",stdin);
    freopen("11957 - Checkers.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    
    fr(t,1,tcs)
    {
        scanf(" %d ",&n);
        int y,x;
        rep(i,n)
        {
            gets(a[i]);
            rep(j,n) 
            {
                step[i][j] = 0;
                if(a[i][j] == 'W')
                {
                    x = j;
                    y = i;
                }
            }
        }
        
        //DEBUG(y);
        //DEBUG(x);
        printf("Case %d: %d\n",t,DFS(y,x));
        //rep(i,n)
        //{
        //    rep(j,n) printf("%3d ",step[i][j]);
        //    printf("\n");
        //}
    }
    
    return 0;
}