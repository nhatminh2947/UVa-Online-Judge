//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10525 - New to Bangladesh
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

int n,m;
int dist[505][505], tm[505][505];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10525 - New to Bangladesh.INP","r",stdin);
    freopen("10525 - New to Bangladesh.OUT","w",stdout);
    #endif
    
    int tcs;
    read(tcs);
    
    fr(t,1,tcs)
    {
        if(t != 1) puts("");
        
        read2(n,m);
        
        fr(i,1,n)
            fr(j,1,n)
                tm[i][j] = dist[i][j] = (i == j) ? 0 : INF;
        
        rep(i,m)
        {
            int u,v,d,w;
            read2(u,v);
            read2(w,d);
            
            if(tm[u][v] > w)
            {
                dist[u][v] = dist[v][u] = d;
                tm[u][v] = tm[v][u] = w;
            }
            else if(tm[u][v] == w && dist[u][v] > d)
            {
                dist[u][v] = dist[v][u] = d;
                tm[u][v] = tm[v][u] = w;
            }
        }
        
        fr(k,1,n)
            fr(i,1,n)
                fr(j,1,n)
                {
                    if(tm[i][j] > tm[i][k] + tm[k][j])
                    {
                        tm[i][j] = tm[i][k] + tm[k][j];
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                    else if(tm[i][j] == tm[i][k] + tm[k][j] && dist[i][j] > dist[i][k] + dist[k][j])
                    {
                        tm[i][j] = tm[i][k] + tm[k][j];
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
        
        int q;
        read(q);
        
        fr(i,1,q)
        {
            int u,v;
            read2(u,v);
            
            if(tm[u][v] == INF) puts("No Path.");
            else printf("Distance and time to reach destination is %d & %d.\n",dist[u][v],tm[u][v]);
        }
    }
    
    return 0;
}
