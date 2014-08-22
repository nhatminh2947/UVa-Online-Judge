//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 12532 - Interval Product
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
#define maxN 10000000

char s[1000];
int n,m;
int treeAns[5000000];
int a[1000005];

int buildAns(int node, int lf, int rg)
{
    if(lf == rg) return treeAns[node] = a[lf];
    
    int u = buildAns(node*2  ,         lf,(lf+rg)/2);
    int v = buildAns(node*2+1,(lf+rg)/2+1,       rg);
    
    return treeAns[node] = u*v;
}

int getAns(int node, int lf, int rg, int LF, int RG)
{
    if(rg < LF || RG < lf)
        return 2;
    
    if(LF <= lf && rg <= RG)
        return treeAns[node];
    
    int u = getAns(node*2  ,         lf,(lf+rg)/2,LF,RG);
    int v = getAns(node*2+1,(lf+rg)/2+1,       rg,LF,RG);
    
    if(u == 2) return v;
    if(v == 2) return u;
    
    return u*v;
}

int updateAns(int node, int lf, int rg, int pos)
{
    if(lf == rg && rg == pos)
        return treeAns[node] = a[pos];
    
    if(rg < pos || pos < lf)
        return treeAns[node];
    
    int u = updateAns(node*2  ,         lf,(lf+rg)/2,pos);
    int v = updateAns(node*2+1,(lf+rg)/2+1,       rg,pos);
    
    return treeAns[node] = u*v;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("12532 - Interval Product.INP","r",stdin);
    freopen("12532 - Interval Product.OUT","w",stdout);
    #endif
    
    while(gets(s))
    {
        //DEBUG(s);
        sscanf(s," %d %d ",&n,&m);
        
        fr(i,1,n)
        {
            int x;
            scanf(" %d ",&x);
            if(x < 0) a[i] = -1;
            else if(x > 0) a[i] = 1;
            else a[i] = 0;
            //DEBUG(x);
        }
        
        //DEBUG(n);
        buildAns(1,1,n);
        
        rep(i,m)
        {
            char c;
            int u,v;
            sscanf(gets(s)," %c %d %d ",&c,&u,&v);
            
            if(c == 'C')
            {
                if(v < 0) a[u] = -1;
                else if(v > 0) a[u] = 1;
                else a[u] = 0;
                
                updateAns(1,1,n,u);
            }
            else
            {
                int ans = getAns(1,1,n,u,v);
                
                if(ans == 1) printf("+");
                else if(ans == 0) printf("0");
                else printf("-");
            }
        }
        printf("\n");
    }
    
    return 0;
}
