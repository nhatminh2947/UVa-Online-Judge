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
#define maxN 1005

vector <int> adj[maxN];
bool vis[maxN];
int n, m;

void dfs(int u) {
    vis[u] = true;
    for (int i = 0; i < adj[u].size(); i++)
        if (!vis[adj[u][i]])
            dfs(adj[u][i]);
    
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("I.INP","r",stdin);
    //freopen(".OUT","w",stdout);
    #endif
    
    while (read2(n,m)) {
        for (int i = 0; i <= n; i++) {
            vis[i] = false;
            adj[i].clear();
        }
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u].pb(v);
        }
        int ans = 0;
        vector <int> disvis;
        for (int i = 0; i <= n; i++)
            if (!vis[i]) {
                disvis.pb(i);
                dfs(i);
            }
        reverse(all(disvis));
        for (int i = 0; i <= n; i++)
            vis[i] = false;
        for (int i = 0; i < sz(disvis) ; i++) 
            if (!vis[disvis[i]]){
                dfs(disvis[i]);
                ans++;
            }
        printf("%d\n", ans - 1);
    }
    
    return 0;
}
