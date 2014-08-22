//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11902 - Dominator
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

int n;
int a[105][105];
bool reachable[105],vis[105],d[105][105];

void DFS(int u, int ignore)
{
    if(u == ignore) return;
    
    if(ignore == -1)
    {
        reachable[u] = true;
        fr(v,1,n) 
            if(!reachable[v] && a[u][v])
                DFS(v,ignore);
        return;
    }
    
    vis[u] = true;
    fr(v,1,n) 
        if(!vis[v] && a[u][v])
            DFS(v,ignore);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11902 - Dominator.INP","r",stdin);
    freopen("11902 - Dominator.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    
    fr(t,1,tcs)
    {
        scanf(" %d ",&n);
        
        rep(i,n)
        {
            reachable[i] = false;
            rep(j,n) scanf(" %d ",&a[i][j]);
        }
        
        DFS(0,-1);
        
        rep(u,n)
        {
            rep(i,n) vis[i] = false;
            
            DFS(0,u);
            
            rep(v,n)
                if(!vis[v] && reachable[v])
                    d[u][v] = true;
                else d[u][v] = false;
        }
        
        d[0][0] = true;
        
        printf("Case %d:\n",t);
        
        rep(i,n)
        {
            printf("+"); rep(j,n*2-1) printf("-"); puts("+");
            
            rep(j,n) printf("|"), printf((d[i][j] ? "Y":"N")); puts("|");
        }
        printf("+"); rep(j,n*2-1) printf("-"); puts("+");
    }
    
    return 0;
}
