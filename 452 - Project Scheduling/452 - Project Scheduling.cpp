//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 452 - Project Scheduling
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

vi adj[300];
int w[300];
int dist[300];

int DFS(int u)
{
    if(dist[u] != -1) return dist[u];
    //DEBUG(char(u));
    int ans = -INF;
    rep(i,sz(adj[u]))
    {
        int v = adj[u][i];
        //DEBUG(char(v));
        ans = max(ans,DFS(v)+w[u]);
    }
    
    return dist[u] = max(w[u],ans);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("452 - Project Scheduling.INP","r",stdin);
    freopen("452 - Project Scheduling.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    
    bool blank = false;
    rep(t,tcs)
    {
        if(blank) printf("\n");
        blank = true;
        
        fr(i,'A','Z')
        {
            adj[i].clear();
            w[i] = 0;
            dist[i] = -1;
        }
        
        vector<char> toDo;
        char str[1000];
        while(gets(str) && str[0] != '\0')
        {
            char u;
            char s[100];
            int d;
            
            int check = sscanf(str,"%c %d %s",&u,&d,&s);
            w[u] = d;
            if(check == 2)
            {
                toDo.pb(u);
                continue;
            }
            
            for(int i = 0 ; s[i] ; i++)
                adj[s[i]].pb(u);
        }
        
        int ans = -INF;
        
        rep(i,sz(toDo)) ans = max(ans,DFS(toDo[i]));
        
        printf("%d\n",ans);
    }
    
    return 0;
}
