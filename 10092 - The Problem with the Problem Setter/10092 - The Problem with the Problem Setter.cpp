//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10092 - The Problem with the Problem Setter
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

int n,m,f,s,t,maxi;
vi adj[1055];
int e[1055][1055];
int p[1055];

int augment(int v, int minEdge)
{
    if(v == 0) return f = minEdge;
    else if(v != -1)
    {
        augment(p[v],min(e[p[v]][v],minEdge));
        
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
        fr(i,0,t) p[i] = -1;
        
        queue<int> q;
        q.push(0);
        p[0] = 0;
        
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
    freopen("10092 - The Problem with the Problem Setter.INP","r",stdin);
    freopen("10092 - The Problem with the Problem Setter.OUT","w",stdout);
    #endif
    
    while(read2(n,m) && n)
    {
        maxi = 0;
        s = 0;
        t = n + m + 1;
        
        fr(i,0,t)
        {
            fr(j,0,t) e[i][j] = 0;
            adj[i].clear();
        }
        
        fr(i,1,n)
        {
            read(e[i][t]);
            maxi += e[i][t];
            adj[i].pb(t);
            adj[t].pb(i);
        }
        
        fr(i,1,m)
        {
            int k;
            read(k);
            rep(j,k)
            {
                int x;
                read(x);
                adj[n+i].pb(x);
                adj[x].pb(n+i);
                e[n+i][x] = 1;
            }
            
            adj[0].pb(n+i);
            adj[n+i].pb(0);
            e[0][n+i] = 1;
        }
        
        int ans = maxFlow();
        if(ans == maxi) puts("1");
        else puts("0");
        
        if(ans == maxi)
        {
            fr(i,1,n)
            {
                bool sp = false;
                fr(j,1,m)
                    if(e[i][n+j])
                    {
                        if(sp) printf(" ");
                        sp = true;
                        printf("%d",j);
                    }
                puts("");
            }
        }
    }
    
    return 0;
}

