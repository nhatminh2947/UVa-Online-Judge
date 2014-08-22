//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 821 - Page Hopping
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
#define maxN 100000

int n;
int adj[105][105];

void reset()
{
    fr(i,1,100) fr(j,1,100)
        adj[i][j] = INF;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("821 - Page Hopping.INP","r",stdin);
    freopen("821 - Page Hopping.OUT","w",stdout);
    #endif
    
    int u,v;
    int tcs = 1;
    while(scanf("%d %d",&u,&v) && u)
    {
        n = -INF;
        reset();
        adj[u][v] = 1;
        adj[u][u] = adj[v][v] = 0;
        n = max(n,max(u,v));
        
        while(scanf("%d %d",&u,&v) && u)
        {
            adj[u][v] = 1;
            adj[u][u] = adj[v][v] = 0;
            n = max(n,max(u,v));
        }
            
        fr(k,1,n)
            fr(i,1,n)
                fr(j,1,n)
                    adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);
        
        int sum = 0;
        int cnt = 0;
        
        fr(i,1,n) fr(j,1,n) 
            if(adj[i][j] != INF && i != j)
            {
                sum += adj[i][j];
                cnt++;
            }
            
        printf("Case %d: average length between pages = %.3lf clicks\n",tcs++,(double)sum/cnt);
    }
    
    return 0;
}
