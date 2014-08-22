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
#define maxN 100000

int f[1005][1005], trace[1005], w[1005][1005];
map <char, int> :: iterator it;
vector <map<char, int> > vocas,challen;
int v, c;

bool solve(int u, int v) {
    for (it = challen[v].begin(); it != challen[v].end(); it++)
        if (vocas[u][it->first] < it->second)
            return false;
    return true;
            
}

bool findpath() {
    for (int i = 1; i <= v + c + 1; i++)
        trace[i] = INF;
    queue <int> q;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        
        if (u == v + c + 1)
            return true;
        q.pop();
        for (int i = 1; i <= v + c + 1; i++)
            if (trace[i] == INF && f[u][i] < w[u][i]) {
                trace[i] = u;
                if (i == v + c + 1)
                    return true;
                q.push(i);
            }
    }
    return false;
}
void incFlow() {
    int des = v + c + 1;
    int u = trace[des];
    while (u != 0) {
        u = trace[des];
        f[u][des] += 1;
        f[des][u] -= 1;
        des = u;
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("h.INP","r",stdin);
    freopen("h.OUT","w",stdout);
    #endif
    
    
    while (scanf("%d %d", &v, &c) != -1) {
        vocas.clear();
        challen.clear();
        for (int i = 0; i < v; i++) {
            char s[35];
            scanf("%s", &s);
            map <char, int> tmp;
            for (int i = 0, sz = strlen(s); i < sz; i++)
                tmp[s[i]]++;
            vocas.pb(tmp);
        }
        for (int i = 0; i < c; i++) {
            char s[35];
            scanf("%s", &s);
            map <char, int> tmp;
            for (int i = 0, sz = strlen(s); i < sz; i++)
                tmp[s[i]]++;
            challen.pb(tmp);
        }
        
        for (int i = 0; i <= 1001; i++)
            for (int j = i+1; j <= 1001; j++)
                {
                    w[i][j] = w[j][i]=0;
                     f[i][j] =f[j][i]= 0;
                }
                
        for (int i = 0; i < v; i++)
            for (int j = 0; j < c; j++)
                if (solve(i, j))
                    w[i + 1][j + v + 1] = 1;
        for (int i = 1; i <= v; i++)
            w[0][i] = 1;
        for (int i = v + 1; i <= v + c; i++)
            w[i][v + c + 1] = 1;
            
        while (findpath()) {
            incFlow();
        }
        int ans = 0;
        for (int i = v + 1; i <= v + c; i++)
            ans += f[i][v + c + 1];
        printf("%d\n", ans);
    }
    
    
    return 0;
}
