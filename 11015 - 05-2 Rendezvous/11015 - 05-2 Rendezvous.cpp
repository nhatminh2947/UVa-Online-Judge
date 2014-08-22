//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11015 - 05-2 Rendezvous
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

char a[25][15];
int n,m;
int adj[300][300];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11015 - 05-2 Rendezvous.INP","r",stdin);
    freopen("11015 - 05-2 Rendezvous.OUT","w",stdout);
    #endif
    
    int t = 1;
    while(read2(n,m) && n)
    {
        getchar();
        fr(i,1,n) gets(a[i]);
        
        fr(i,1,n)
            fr(j,1,n)
            {
                adj[i][j] = INF;
                if(i == j) adj[i][j] = 0;
            }
        
        rep(i,m)
        {
            int u,v,w;
            read3(u,v,w);
            
            adj[u][v] = adj[v][u] = w;
        }
        
        fr(k,1,n)
            fr(i,1,n)
                fr(j,1,n)
                    adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);
            
        int sum = INF;
        int ans = 0;
        fr(i,1,n)
        {
            int tmp = 0;
            fr(j,1,n)
                tmp += adj[i][j];
            
            if(sum > tmp)
            {
                sum = tmp;
                ans = i;
            }
        }
        
        printf("Case #%d : %s\n",t++,a[ans]);
    }
    
    return 0;
}
