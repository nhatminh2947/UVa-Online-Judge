//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 336 - A Node Too Far
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

int n,cnt;
vector<int> a[35];
map<int,int> m;
int step[35];

void BFS(int k, int ttl)
{
    queue<int> q;
    q.push(k);
    step[k] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        //DEBUG(u);
        for(int i = 0 ; i < sz(a[u]) ; i++)
        {
            int v = a[u][i];
            //DEBUG(v);
            if(step[v] == -1)
            {
                step[v] = step[u] + 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("336 - A Node Too Far.INP","r",stdin);
    freopen("336 - A Node Too Far.OUT","w",stdout);
    #endif
    int tcs = 0;
    while(scanf(" %d ",&n) && n)
    {
        cnt = 0;
        m.clear();
        fr(i,1,33) a[i].clear();
        //DEBUG(n);
        rep(i,n)
        {
            int u,v;
            scanf(" %d %d ",&u,&v);
            if(!m[u])
                m[u] = ++cnt;
            if(!m[v])
                m[v] = ++cnt;
            int mu = m[u];
            int mv = m[v];
            a[mu].pb(mv);
            a[mv].pb(mu);
        }
        
        int node,ttl;
        while(scanf(" %d %d ",&node,&ttl))
        {
            if(node == 0 && ttl == 0) break;
            fr(i,1,33) step[i] = -1;
            BFS(m[node],ttl);
            int ans = 0;
            for(int i = 1 ; i <= cnt ; i++)
                if(step[i] == -1 || step[i] > ttl)
                    ans++;
            //DEBUG(node);
            //DEBUG(ttl);
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++tcs, ans, node, ttl);
        }
    }

    return 0;
}