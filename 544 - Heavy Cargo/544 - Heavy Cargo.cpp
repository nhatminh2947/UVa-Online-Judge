//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 544 - Heavy Cargo
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

map<string,int> m;
int dist[205][205];
int n,r;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("544 - Heavy Cargo.INP","r",stdin);
    freopen("544 - Heavy Cargo.OUT","w",stdout);
    #endif
    int tcs = 1;
    while(read2(n,r) && n)
    {
        m.clear();
        fr(i,1,n)
            fr(j,1,n)
            {
                if(i == j) dist[i][j] = 0;
                else dist[i][j] = -1;
            }
        
        int tmp = n;
        rep(i,r)
        {
            string u,v;
            int w;
            read3(u,v,w);
            
            if(!m.count(u))
                m[u] = tmp--;
            if(!m.count(v))
                m[v] = tmp--;
            
            dist[m[u]][m[v]] = dist[m[v]][m[u]] = max(dist[m[u]][m[v]],w);
        }
        
        fr(k,1,n)
            fr(i,1,n)
                fr(j,1,n)
                    dist[i][j] = max(dist[i][j],min(dist[i][k],dist[k][j]));
                
        string st,ed;
        read2(st,ed);
        //DEBUG(st);
        //DEBUG(ed);
        printf("Scenario #%d\n%d tons\n\n",tcs++,dist[m[st]][m[ed]]);
    }
    
    return 0;
}
