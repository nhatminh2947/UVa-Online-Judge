//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 168 - Theseus and the Minotaur
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

vector<int> adj[300];
bool vis[300];
int k;

void DFS(int T, int M, int step)
{
    vis[M] = !((++step)%k);
    int len = adj[M].size();
    
    rep(i,len)
    {
        int v = adj[M][i];
        if(!vis[adj[M][i]] && v != T)
        {
            if(vis[M]) printf("%c ",M);
            return DFS(M,v,step);
        }
    }
    
    printf("/%c\n",M);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("168 - Theseus and the Minotaur.INP","r",stdin);
    freopen("168 - Theseus and the Minotaur.OUT","w",stdout);
    #endif
    
    char s[300];
    
    while(gets(s) && s[0] != '#')
    {
        k = 0;
        fr(i,'A','Z')
        {
            vis[i] = false;
            adj[i].clear();
        }
        int len = strlen(s);
        
        int u,v;
        int i = 0;
        while(i != len)
        {
            u = s[i];
            i+=2;
            
            while(s[i] != ';' && s[i] != '.')
            {
                adj[u].pb(s[i]);
                i++;
            }
            
            if(s[i] == '.')
            {
                v = s[i+2];
                u = s[i+4];
                
                i += 6;
                while('0' <= s[i] && s[i] <= '9') k = k*10 + s[i++] - '0';
                break;
            }
            
            i++;
        }
        DFS(u,v,0);
    }
    
    return 0;
}