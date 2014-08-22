//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10986
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

int tcs,n,m,a,b,w,S,T;
int dist[20005];
set< pair<int,int> > s;
vector< pair<int,int> > obj[20005];

int dijkstra()
{
    s.clear();
    for(int i=0;i<=n;i++)
    {
        vis[i]=false;
        dist[i]=INF;
    }
    
    s.insert(make_pair(0,S));
    
    while(!s.empty())
    {
        pair<int,int> u=*s.begin();
        int pos=u.second;
        
        if(pos==T) return dist[T];
        
        s.erase(u);
        
        for(int j=0;j<obj[pos].size();j++)
        {
            int v = obj[pos][j].first;
            int d = obj[pos][j].second;
            if(dist[u] + d < dist[v])
            {
                if(dist[v]!=INF)
                    s.erase(make_pair(dist[v],v));
                dist[v] = dist[u] + d;
                s.insert(make_pair(dist[v],v));
            }
        }
    }
    
    return INF;
}

int main()
{
    //freopen("10986.INP","r",stdin);
    //freopen("10986.OUT","w",stdout);
    scanf("%d",&tcs);
    for(int i=1;i<=tcs;i++)
    {
        scanf("%d%d%d%d",&n,&m,&S,&T);
        for(int j=0;j<=n;j++) 
            obj[j].clear();
        for(int j=0;j<m;j++)
        {
            scanf("%d%d%d",&a,&b,&w);
            obj[a].push_back(make_pair(b,w));
            obj[b].push_back(make_pair(a,w));
        }
        int res=dijkstra();
        if(res==INF) printf("Case #%d: unreachable\n",i);
        else printf("Case #%d: %d\n",i,res);
    }
    return 0;
}
