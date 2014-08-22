//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11307 - Alternative Arborescence
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

char s[1000005];
vi adj[10005];
bool vis[10005];
int n;
int dp[10005][25];

int DFS(int u, int color)
{
    //printf("u = %d color = %d\n",u,color);
    if(dp[u][color] != INF) return dp[u][color];
    
    int ans = color;
    //DEBUG(sz(adj[u]));
    rep(i,sz(adj[u]))
    {
        int v = adj[u][i];
        int k = INF;
        //DEBUG(v);
        if(!vis[v])
        {
            vis[v] = true;
            fr(j,1,6)
            {
                if(j != color)
                {
                    k = min(k,DFS(v,j));
                }
            }
            vis[v] = false;
            ans += k;
        }
    }
    
    return dp[u][color] = ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11307 - Alternative Arborescence.INP","r",stdin);
    freopen("11307 - Alternative Arborescence.OUT","w",stdout);
    #endif
    
    while(gets(s))
    {
        n = 0;
        int l = strlen(s);
        rep(i,l)
            n = n*10 + s[i] - '0';
        //DEBUG(s);
        if(n == 0) break;    
        //getchar();
        
        rep(i,n)
        {
            adj[i].clear();
            vis[i] = false;
            fr(j,1,6) dp[i][j] = INF;
        }
        
        rep(i,n)
        {
            gets(s);
            int len = strlen(s);
            
            bool ok = false;
            int j = 0;
            int u = 0;
            int v = 0;
            while(s[j] != ':')
                u = u*10 + s[j++] - '0';
            
            //DEBUG(u);
            j+=2;
            
            for(; j < len ; j++)
            {
                if(s[j] == ' ')
                {
                    adj[u].pb(v);
                    adj[v].pb(u);
                    //DEBUG(v);
                    v = 0;
                }
                else
                {
                    v = v*10 + s[j] - '0';
                    ok = true;
                }
            }
            
            if(ok)
            {
                adj[u].pb(v);
                adj[v].pb(u);
                //DEBUG(v);
            }
        }
        int ans = INF;
        fr(i,1,6)
        {
            vis[0] = true;
            ans = min(ans,DFS(0,i));
            vis[0] = false;
        }
        printf("%d\n",ans);
        getchar();
    }
    
    return 0;
}
