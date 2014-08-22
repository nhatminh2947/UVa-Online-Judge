//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 315 - Network
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
#define maxN 100

int n,id,cnt,dfsRoot,rootChildren;
vi adj[maxN+5];
int low[maxN+5],ind[maxN+5],parent[maxN+5];
bool check[maxN+5];

void reset()
{
    id = cnt = 0;
    fr(i,1,n)
    {
        adj[i].clear();
        low[i] = ind[i] = 0;
        parent[i] = i;
        check[i] = false;
    }
}

void Point(int u)
{
    low[u] = ind[u] = ++id;
    
    rep(i,sz(adj[u]))
    {
        int v = adj[u][i];
        
        if(!ind[v])
        {
            parent[v] = u;
            if(u == dfsRoot) rootChildren++;
            
            Point(v);
            
            if(low[v] >= ind[u] && !check[u])
            {
                cnt++;
                check[u] = true;
            }
            
            low[u] = min(low[u],low[v]);
        }
        else if(parent[u] != v) low[u] = min(low[u],ind[v]);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("315 - Network.INP","r",stdin);
    freopen("315 - Network.OUT","w",stdout);
    #endif
    
    while(scanf(" %d ",&n) && n)
    {
        reset();
        char s[1000];
        while(gets(s) && s[0] != '0')
        {
            //DEBUG(s);
            int u,v;
            u = v = 0;
            //int len = strlen(s);
            int i = 0;
            while(s[i] != ' ')
            {
                u = u*10 + s[i++]-'0';
                //i++;
            }
            //DEBUG(i);
            i++;
            for(;s[i];i++)
            {
                //DEBUG(s[i]);
                if(s[i] == ' ')
                {
                    adj[u].pb(v);
                    adj[v].pb(u);
                    v = 0;
                }
                else v = v*10 + s[i] - '0';
            }
            
            if(v)
            {
                adj[u].pb(v);
                adj[v].pb(u);
            }
        }
        
        fr(i,1,n)
            if(!ind[i])
            {
                dfsRoot = i;
                rootChildren = 0;
                Point(i);
                if(rootChildren <= 1) cnt--;
            }
        
        printf("%d\n",cnt);
    }
    
    return 0;
}
