//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10610 - Gopher and Hawks
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
#define maxN 1000

int v,m;
vector< pair<double,double> > h;
vi adj[maxN+5];
int step[maxN+5];
char s[1000];

double dist(pair<double,double> a, pair<double,double> b)
{
    return sqrt((a.ff-b.ff) * (a.ff-b.ff) + (a.ss-b.ss) * (a.ss-b.ss));
}

int BFS()
{
    rep(i,sz(h)) step[i] = -1;
    
    queue<int> q;
    q.push(0);
    step[0] = 0;
    
    while(!q.empty())
    {
        int u = q.front();
        
        if(u == 1) return step[u];
        q.pop();
        
        rep(i,sz(adj[u]))
        {
            int v = adj[u][i];
            
            if(step[v] == -1)
            {
                step[v] = step[u] + 1;
                q.push(v);
            }
        }
    }
    
    return -1;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10610 - Gopher and Hawks.INP","r",stdin);
    freopen("10610 - Gopher and Hawks.OUT","w",stdout);
    #endif
    
    while(read2(v,m) && (v+m))
    {
        h.clear();
        m *= 60;
        pair<double,double> st,ed;
        scanf("%lf %lf",&st.ff,&st.ss);
        scanf("%lf %lf",&ed.ff,&ed.ss);
        getchar();
        
        h.pb(st);
        h.pb(ed);
        
        while(gets(s) && s[0] != 0)
        {
            double a,b;
            sscanf(s,"%lf %lf",&a,&b);
            
            h.pb(mp(a,b));
        }
        
        rep(i,sz(h)) adj[i].clear();
        
        rep(i,sz(h))
            for(int j = i+1 ; j < sz(h) ; j++)
            {
                double d = dist(h[i],h[j]);
                
                if(d/v > m) continue;
                
                adj[i].pb(j);
                adj[j].pb(i);
            }
        
        int ans = BFS();
        
        if(ans == -1) puts("No.");
        else printf("Yes, visiting %d other holes.\n",ans-1);
    }
    
    return 0;
}
