//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10543 - Traveling Politician
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

int n,m,k;
vi adj[55];
int step[55][100005];

int BFS()
{
    rep(i,n)
        rep(j,100000)
            step[i][j] = -1;
    
    queue<ii> q;
    q.push(mp(0,1));
    step[0][1] = 1;
    
    while(!q.empty())
    {
        int u = q.front().ff;
        int d = q.front().ss;
        
        if(d > 20) return -1;
        
        if(u == n-1 && d >= k)
            return step[u][d];
        
        q.pop();
        
        rep(i,sz(adj[u]))
        {
            int v = adj[u][i];
            
            if(d+1 < 100000 && step[v][d+1] == -1)
            {
                step[v][d+1] = d+1;
                q.push(mp(v,d+1));
            }
        }
    }
    
    return -1;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10543 - Traveling Politician.INP","r",stdin);
    freopen("10543 - Traveling Politician.OUT","w",stdout);
    #endif
    
    while(read3(n,m,k) && n)
    {
        rep(i,n) adj[i].clear();
        
        rep(i,m)
        {
            int u,v;
            read2(u,v);
            adj[u].pb(v);
        }
        
        int ans = BFS();
        if(ans == -1) puts("LOSER");
        else cout << BFS() << endl;
    }
    
    return 0;
}
