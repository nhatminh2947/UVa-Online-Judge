//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11047 - The Scrooge Co Problem
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

map<string,int> m;
string s[105],st,ed;
int dist[105][105];
int path[105][105];
int n,r;

void printPath(int u, int v)
{
    if(u != v)
        printPath(u,path[u][v]);
    if(s[v] != st) printf(" ");
    cout << s[v];
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11047 - The Scrooge Co Problem.INP","r",stdin);
    freopen("11047 - The Scrooge Co Problem.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    fr(t,1,tcs)
    {
        scanf(" %d ",&n);
        m.clear();
        fr(i,1,n)
        {
            cin >> s[i];
            
            m[s[i]] = i;
        }
        
        fr(i,1,n) fr(j,1,n)
        {
            scanf(" %d ",&dist[i][j]);
            if(dist[i][j] == -1) dist[i][j] = INF;
            path[i][j] = i;
        }
        
        fr(k,1,n)
            fr(i,1,n)
                fr(j,1,n)
                    if(dist[i][j] > dist[i][k] + dist[k][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        path[i][j] = path[k][j];
                    }
        
        scanf(" %d ",&r);
        rep(i,r)
        {
            string emp;
            cin >> emp >> st >> ed;
            
            int mu = m[st];
            int mv = m[ed];
            
            if(mu == 0 || mv == 0 || dist[mu][mv] == INF) cout << "Sorry Mr " << emp << " you can not go from " << st << " to " << ed << endl;
            else
            {
                cout << "Mr " << emp << " to go from " << st << " to " << ed << ", you will receive " << dist[mu][mv] << " euros" << endl;
                cout << "Path:"; printPath(mu,path[mu][mv]); cout << " " << s[mv] << endl;
            }
        }
    }
    
    return 0;
}
