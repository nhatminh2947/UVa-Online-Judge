//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10779 - Collectors Problem
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

int n,m,s,t,f;
int p[100];
int e[100][100];
vi adj[100];
int cnt[25][55];

int augment(int v, int minEdge)
{
    if(v == s) return f = minEdge;
    else if(v != -1)
    {
        augment(p[v],min(minEdge,e[p[v]][v]));
        
        e[p[v]][v] -= f;
        e[v][p[v]] += f;
    }
}

int maxFlow()
{
    int mf = 0;
    
    while(1)
    {
        f = 0;
        
        fr(i,s,t) p[i] = -1;
        
        queue<int> q;
        q.push(1);
        p[1] = 0;
        
        while(!q.empty())
        {
            int u = q.front();
            
            q.pop();
            
            if(u == t) break;
            
            rep(i,sz(adj[u]))
            {
                int v = adj[u][i];
                if(e[u][v] > 0 && p[v] == -1)
                {
                    p[v] = u;
                    q.push(v);
                }
            }
        }
        
        augment(t,INF);
        
        if(f == 0) break;
        mf += f;
    }
    
    return mf;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10779 - Collectors Problem.INP","r",stdin);
    freopen("10779 - Collectors Problem.OUT","w",stdout);
    #endif
    
    int tcs;
    read(tcs);
    
    fr(tc,1,tcs)
    {
        read2(n,m);
        
        s = 1;
        t = n+m+1;
        
        fr(i,1,n) fr(j,1,m) cnt[i][j] = 0;
        fr(i,1,t)
        {
            adj[i].clear();
            fr(j,1,t) e[i][j] = 0;
        }
        
        
        fr(i,1,n)
        {
            int k;
            read(k);
            rep(j,k)
            {
                int x;
                read(x);
                cnt[i][x]++;
            }
        }
        
        vi bob;
        fr(x,1,m)
        {
            if(cnt[1][x])
            {
                adj[1].pb(n+x);
                adj[n+x].pb(1);
                
                e[1][n+x] = cnt[1][x];
            }
        }
        
        fr(i,2,n)
        {
            fr(x,1,m)
            {
                if(cnt[i][x])
                {
                    adj[i].pb(n+x);
                    adj[n+x].pb(i);
                    
                    e[i][n+x] = cnt[i][x];
                }
                else if(cnt[1][x])
                {
                    adj[n+x].pb(i);
                    adj[i].pb(n+x);
                    
                    e[n+x][i] = cnt[1][x];
                }
            }
        }
        
        fr(x,1,m)
        {
            adj[n+x].pb(t);
            adj[t].pb(n+x);
            
            e[n+x][t] = 1;
        }
        
        int ans = maxFlow();
        
        printf("Case #%d: %d\n",tc,ans);
    }
    
    return 0;
}

