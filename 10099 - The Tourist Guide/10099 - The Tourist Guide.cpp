//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10099 - The Tourist Guide
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

int n,r;
int dist[105][105];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10099 - The Tourist Guide.INP","r",stdin);
    freopen("10099 - The Tourist Guide.OUT","w",stdout);
    #endif
    int tcs = 1;
    while(read2(n,r) && n)
    {
        fr(i,1,n)
            fr(j,1,n)
                if(i == j)
                    dist[i][j] = 0;
                else dist[i][j] = -1;
        
        rep(i,r)
        {
            int u,v,w;
            read3(u,v,w);
            
            dist[u][v] = dist[v][u] = max(dist[u][v],w);
        }
        
        fr(k,1,n)
            fr(i,1,n)
                fr(j,1,n)
                    dist[i][j] = max(dist[i][j],min(dist[i][k],dist[k][j]));
        
        int u,v,k;
        read3(u,v,k);
        
        printf("Scenario #%d\nMinimum Number of Trips = %d\n\n",tcs++,(k+dist[u][v]-2)/(dist[u][v]-1));

    }
    
    return 0;
}
