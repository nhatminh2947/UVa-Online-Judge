//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10911 - Forming Quiz Teams
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

double d[20][20];
double x[20],y[20];
double ans[70000];
int n;

double dist(int u, int v)
{
    return sqrt((x[u] - x[v]) * (x[u] - x[v]) + (y[u] - y[v]) * (y[u] - y[v]));
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10911 - Forming Quiz Teams.INP","r",stdin);
    freopen("10911 - Forming Quiz Teams.OUT","w",stdout);
    #endif
    int tcs = 1;
    while(scanf(" %d ",&n) && n)
    {
        for(int i = 0 ; i < 2*n ; i++)
        {
            char s[25];
            scanf(" %s %lf %lf ",&s,&x[i],&y[i]);
        }
        
        fr(i,0,n*2-1) fr(j,i+1,n*2) 
            d[i][j] = d[j][i] = dist(i,j);
        
        int k = 1 << (2*n);
        rep(i,k) ans[i] = INF;
        
        vi base;
        queue<int> q;
        
        rep(i,k)
        {
            int cnt = 0;
            int u,v;
            u = v = -1;
            rep(j,2*n)
            {
                int tmp = 1 << j;
                if(tmp & i)
                {
                    if(u == -1) u = j;
                    else v = j;
                    
                    cnt++;
                }
                
                if(cnt > 2)
                    break;
            }
            
            if(cnt == 2)
            {
                ans[i] = min(ans[i],d[u][v]);
                base.pb(i);
                q.push(i);
            }
        }
        
        //BFS
        while(!q.empty())
        {
            rep(j,sz(base))
            {
                if(!(q.front() & base[j]))
                {
                    int tmp = q.front() | base[j];
                    if(ans[tmp] == INF) q.push(tmp);
                    ans[tmp] = min(ans[tmp], ans[q.front()] + ans[base[j]]);
                }
            }
            
            q.pop();
        }
        
        printf("Case %d: %.2lf\n",tcs++,ans[k-1]);
    }
    
    return 0;
}
