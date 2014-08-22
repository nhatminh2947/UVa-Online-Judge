//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10443 - Rock
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

int r,c,n;

bool inside(int y, int x)
{
    return (0 <= x && x < c && 0 <= y && y < r);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10443 - Rock.INP","r",stdin);
    freopen("10443 - Rock.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    rep(t,tcs)
    {
        if(t) printf("\n");
        
        scanf(" %d %d %d ",&r,&c,&n);
        
        char a[105][105],b[105][105];
        rep(i,r)
        {
            gets(a[i]);
            //puts(a[i]);
        }
        
        int dx[] = {-1, 0, 0, 1};
        int dy[] = { 0,-1, 1, 0};
        
        rep(k,n)
        {
            rep(i,r) rep(j,c)
            {
                b[i][j] = a[i][j];
                rep(d,4)
                {
                    int x = j + dx[d];
                    int y = i + dy[d];
                    
                    if(inside(y,x))
                    {
                        if(a[i][j] == 'R' && a[y][x] == 'P')
                        {
                            b[i][j] = 'P';
                        }
                        else if(a[i][j] == 'S' && a[y][x] == 'R')
                        {
                            b[i][j] = 'R';
                        }
                        else if(a[i][j] == 'P' && a[y][x] == 'S')
                        {
                            b[i][j] = 'S';
                        }
                    }
                }
            }
            
            rep(i,r) rep(j,c)
            {
                a[i][j] = b[i][j];
            }
        }
        
        rep(i,r) puts(a[i]);
    }
    
    return 0;
}
