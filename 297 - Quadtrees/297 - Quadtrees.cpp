//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 297 - Quadtrees
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
#define maxN 1000000

vi treeU[maxN+5],treeV[maxN+5];
string u,v;

int solve(string s, int p, vi T[])
{
    //DEBUG(p);
    if(p >= sz(s)) return 0;
    
    if(s[p] == 'e')
    {
        return p; 
    }
    if(s[p] == 'f')
    {
        return p;
    }
    
    if(s[p] == 'p')
    {
        int k = p;
        T[p].pb(k+1);
        k = solve(s,k+1,T);
        
        T[p].pb(k+1);
        k = solve(s,k+1,T);
        
        T[p].pb(k+1);
        k = solve(s,k+1,T);
        
        T[p].pb(k+1);
        k = solve(s,k+1,T);
        
        return k;
    }
}

int DFS(int pU, int pV, int val)
{
    if((u[pU] == 'f' && v[pV] != 'p') || (u[pU] != 'p' && v[pV] == 'f'))
        return val;
    
    if((u[pU] == 'e' && v[pV] != 'p') || (u[pU] != 'p' && v[pV] == 'e'))
        return 0;
    
    int k = max(sz(treeU[pU]),sz(treeV[pV]));
    int ans = 0;
    for(int i = 0 ; i < k ; i++)
    {
        int ppU = pU;
        int ppV = pV;
        
        if(sz(treeU[pU]))
            ppU = treeU[pU][i];
        if(sz(treeV[pV]))
            ppV = treeV[pV][i];
        
        ans += DFS(ppU,ppV,val/4);
    }
    
    return ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("297 - Quadtrees.INP","r",stdin);
    freopen("297 - Quadtrees.OUT","w",stdout);
    #endif
    
    int tcs;
    read(tcs);
    rep(t,tcs)
    {
        read2(u,v);
        
        int tmp = max(sz(u),sz(v));
        fr(i,0,tmp)
        {
            treeV[i].clear();
            treeU[i].clear();
        }
        
        solve(u,0,treeU);
        solve(v,0,treeV);
        
        printf("There are %d black pixels.\n",DFS(0,0,1024));
    }
    
    return 0;
}
