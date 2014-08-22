//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 
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

string s[20];
int x[20];
int y[20];
double d[20][20];
bool check[20];
double tong, kq;
int n;
vi b;

double dist(int u, int v)
{
    return sqrt((x[u] - x[v])*(x[u] - x[v]) + (y[u] - y[v])*(y[u] - y[v]));
}

void solve(int u, int cnt)
{
    if(cnt > n) {
            kq = min(kq,tong);
            return;
    }
    if(check[u])
    {
        solve(u+1,cnt);
        return;
    }
    
    for (int i=1; i<=2*n; i++)
        if (i!=u&&!check[i])
        {
            check[u]=true;
            check[i] = true;
            tong += d[u][i];
            
            solve(i%n + 1,cnt+1);
            
            check[u]=false;
            check[i] = false;
            tong -= d[u][i];
        }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("G.INP","r",stdin);
    freopen("G.OUT","w",stdout);
    #endif
    int tcs = 1;
    while(scanf(" %d ",&n) && n)
    {
        b.clear();
        
        fr(i,1,2*n)
        {
            read3(s[i],x[i],y[i]);
            check[i] = false;
        }
        
        int m = 1 << n;
        
        rep(i,m)
        {
            int cnt = 0;
            rep(j,2*n)
            {
                int k = 1 << j;
                if(k & i) cnt++;
            }
            
            DEBUG(cnt);
            if(cnt == n) b.pb(i);
        }
        
        DEBUG(sz(b));
        
        
        tong = 0;
        kq = INF;
        fr(i,1,2*n-1)
            fr(j,i+1,2*n)
                d[i][j] = d[j][i] = dist(i,j);
        //DEBUG(d[1][2]);        
        //check[1]=true;        
        solve(1,1);
        printf("Case %d: %.2lf\n",tcs++,kq);
        //cout << kq << endl;
        
    }
    
    return 0;
}
