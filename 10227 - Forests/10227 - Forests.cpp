//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10227 - Forests
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

vi adj[105];
bool check[105][105];
int pSet[105];
int n,m;
int difSet;

void initSet(int k)
{
    difSet = k;
    fr(i,1,k)
    {
        adj[i].clear();
        pSet[i] = i;
        fr(j,1,m)
            check[i][j] = false;
    }
}

int findSet(int u)
{
    if(pSet[u] == u) return u;
    return pSet[u] = findSet(pSet[u]);
}

void unionSet(int u, int v)
{
    int fu = findSet(u);
    int fv = findSet(v);
    //DEBUG(fu);
    //DEBUG(fv);
    if(fu != fv)
        difSet--;
    pSet[fu] = fv;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10227 - Forests.INP","r",stdin);
    freopen("10227 - Forests.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf("%d",&tcs);
    
    fr(t,1,tcs)
    {
        if(t != 1) printf("\n");
        scanf("%d %d",&n,&m);
        initSet(n);
        //DEBUG(difSet);
        int u,v;
        char s[1000];
        getchar();
        while(gets(s) && s[0] != '\0')
        {
            //DEBUG(s);
            sscanf(s,"%d %d",&u,&v);
            //printf("u = %d v = %d\n",u,v);
            if(!check[u][v])
            {
                adj[u].pb(v);
                check[u][v] = true;
            }
        }
        
        fr(i,1,n) sort(all(adj[i]));
        
        fr(i,1,n-1)
            fr(j,i+1,n)
            {
                if(sz(adj[i]) == sz(adj[j]))
                {
                    //printf("i = %d j = %d\n",i,j);
                    bool ok = true;
                    rep(k,sz(adj[i]))
                    {
                        if(adj[i][k] != adj[j][k])
                        {
                            ok = false;
                            break;
                        }
                    }
                    
                    if(ok)
                    {
                        //cout << "AAA" << endl;
                        unionSet(i,j);
                    }
                }
            }
        
        printf("%d\n",difSet);
    }
    
    return 0;
}
