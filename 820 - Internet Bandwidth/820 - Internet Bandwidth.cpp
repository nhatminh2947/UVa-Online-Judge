//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 820 - Internet Bandwidth
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
#define maxN 100

int n,s,t,c,f;
int path[maxN+5], edge[maxN+5][maxN+5];
bool vis[maxN+5];

void augment(int v, int minEdge)
{
    if(v == s)
    {
        f = minEdge;
        return;
    }
    
    if(path[v] != -1)
    {
        augment(path[v],min(minEdge,edge[path[v]][v]));
    
        edge[path[v]][v] -= f;
        edge[v][path[v]] += f;
    }
}

int maxFlow()
{
    int mf = 0;
    
    while(1)
    {
        f = 0;
        
        fr(i,1,n)
        {
            path[i] = -1;
            vis[i] = false;
        }
        queue<int> q;
        q.push(s);
        vis[s] = true;
        
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            if(u == t) break;
            
            fr(v,1,n)
            {
                if(edge[u][v] > 0 && !vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                    
                    path[v] = u;
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
    freopen("820 - Internet Bandwidth.INP","r",stdin);
    freopen("820 - Internet Bandwidth.OUT","w",stdout);
    #endif
    int tcs = 1;
    while(read(n) && n)
    {
        read3(s,t,c);
        fr(i,1,n) fr(j,1,n) edge[i][j] = 0;
        
        rep(i,c)
        {
            int u,v,w;
            read3(u,v,w);
            edge[u][v] += w;
            edge[v][u] += w;
        }
        
        int ans = maxFlow();
        
        printf("Network %d\n",tcs++);
        printf("The bandwidth is %d.\n\n",ans);
    }
    
    return 0;
}

