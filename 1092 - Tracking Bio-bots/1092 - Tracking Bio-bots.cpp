//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1092 - Tracking Bio-bots
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
#define maxN 1000000

vector<ii,ii> v;
int r[maxN+5],u[maxN+5];

bool cmp(vector<ii,ii> a, vector<ii,ii> b)
{
    return a.ss > b.ss;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1092 - Tracking Bio-bots.INP","r",stdin);
    freopen("1092 - Tracking Bio-bots.OUT","w",stdout);
    #endif
    int n,m,w;
    int tcs = 1;
    while(read3(n,m,w) && n)
    {
        rep(i,maxN) r[i] = u[i] = INF;
        printf("Case %d: ",tcs++);
        
        rep(i,w)
        {
            int x1,x2,y1,y2;
            read2(x1,y1);
            read2(x2,y2);
            
            r[y1] = min(r[y1],x1);
            
            if(u[x1] == -1) u[x1] = y1;
            else u[x1] = min(y[x1],y1);
            
            if(u[x2] == INF)
                u[x2] = -1;
            else if(u[x2] == -1)
                u[x2] = y2;
            else u[x2] = min(u[x2], y2);
        }
        
        int mi = INF;
        rep(i,m)
        {
            if(u[i] == -1)
            {
                u[i] = mi;
                mi = INF;
                continue;
            }
            u[i] = min(u[i],mi);
        }
        
        int x,y;
        y = 0;
        while(y < n)
        {
            while()
            {
                x = r[y];
                y = u[x];
            }
        }
        
    }

    return 0;
}