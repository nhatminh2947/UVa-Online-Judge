//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10054 – the necklace
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

int n,st;
int edge[60][60];
int d[60];
bool vis[60];

void reset()
{
    st = -INF;
    fr(i,1,50)
    {
        vis[i] = false;
        d[i] = 0;
        fr(j,1,50) edge[i][j] = 0;
    }
}

void visit(int u)
{
    fr(v,1,st)
    {
        if(!vis[v] && edge[u][v])
        {
            vis[v] = true;
            visit(v);
        }
    }
}

void DFS(int u)
{
    fr(v,1,st)
    {
        if(edge[u][v])
        {
            edge[u][v]--;
            edge[v][u]--;
            DFS(v);
            printf("%d %d\n",v,u);
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10054 – the necklace.INP","r",stdin);
    freopen("10054 – the necklace.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    
    fr(t,1,tcs)
    {
        if(t != 1) printf("\n");
        scanf(" %d ",&n);
        
        reset();
        
        rep(i,n)
        {
            int u,v;
            scanf(" %d %d ",&u,&v);
            edge[u][v]++;
            edge[v][u]++;
            d[u]++;
            d[v]++;
            st = max(st,max(u,v));
        }
        
        vis[st] = true;
        visit(st);
        bool imp = true;
        fr(i,1,st) if(d[i]%2 || (d[i] && !vis[i]))
        {
            imp = false;
            break;
        }
        
        printf("Case #%d\n",t);
        if(imp) DFS(st);
        else printf("some beads may be lost\n");
    }

    return 0;
}