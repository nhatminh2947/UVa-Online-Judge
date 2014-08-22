//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11045 - My T-shirt suits me
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

map<string,int> id;
int e[105][105];
int p[105];
int n,m,f;

void init()
{
    id["XXL"] = 1;
    id["XL"] = 2;
    id["L"] = 3;
    id["M"] = 4;
    id["S"] = 5;
    id["XS"] = 6;
}

int augment(int v, int minEdge)
{
    if(v == 0)
        return f = minEdge;
    
    if(v != -1)
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
        fr(i,0,100)
            p[i] = -1;
        
        queue<int> q;
        q.push(0);
        p[0] = 0;
        
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            
            if(u == 100) break;
            
            fr(v,0,100)
            {
                if(e[u][v] > 0 && p[v] == -1)
                {
                    p[v] = u;
                    q.push(v);
                }
            }
        }
        
        augment(100,INF);
        
        if(f == 0) break;
        
        mf += f;
    }
    
    return mf;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11045 - My T-shirt suits me.INP","r",stdin);
    freopen("11045 - My T-shirt suits me.OUT","w",stdout);
    #endif
    
    int tcs;
    
    init();
    read(tcs);
    
    fr(t,1,tcs)
    {
        read2(n,m);
        
        fr(i,0,100) fr(j,0,100) e[i][j] = 0;
        
        fr(i,1,6) e[0][i] = n/6;
        fr(i,7,6+m) e[i][100] = 1;
        
        fr(i,7,6+m)
        {
            string s;
            read(s);
            e[id[s]][i] = 1;
            read(s);
            e[id[s]][i] = 1;
        }
        
        int ans = maxFlow();
        
        printf("%s\n",(ans == m) ? "YES" : "NO");
    }
    
    return 0;
}

