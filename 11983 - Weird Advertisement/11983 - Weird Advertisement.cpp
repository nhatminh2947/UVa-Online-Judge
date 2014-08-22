//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11983 - Weird Advertisement
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

struct edge
{
    int y1,y2;
    int x;
    int k;
};

struct Node
{
    int maxi, mini;
    int left, right;
    int sum;
};

const int lim = 1e9;
int a[30005];
int IT[10000005];
int n,k;
vector<edge> e;

void Add(int node, int lf, int rg, int LF, int RG)
{
    if(rg < LF || RG < lf) return;
    
    if(LF <= lf && rg <= RG)
    {
        IT[node]++;
        return;
    }
    
    Add(node*2,lf,(lf+rg)/2,LF,RG);
    Add(node*2+1,(lf+rg)/2+1,rg,LF,RG);
}

void Sub(int node, int lf, int rg, int a, int b)
{
    if(rg < a || b < lf) return;
    
    if(a <= lf && rg <= b)
    {
        IT[node]--;
        return;
    }
    
    if(IT[node] == 0)
    {
        Sub(node*2,lf,(lf+rg)/2,a,b);
        Sub(node*2+1,(lf+rg)/2+1,rg,a,b);
    }
}

bool cmp(edge u, edge v)
{
    return u.x < v.x;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11983 - Weird Advertisement.INP","r",stdin);
    freopen("11983 - Weird Advertisement.OUT","w",stdout);
    #endif
    
    int tcs;
    read(tcs);
    
    fr(t,1,tcs)
    {
        e.clear();
        
        read2(n,k);
        
        rep(i,1000000) IT[i] = 0;
        
        rep(i,n)
        {
            int x1,x2,y1,y2;
            read2(x1,y1);
            read2(x2,y2);
            
            edge tmp;
            tmp.y1 = y1;
            tmp.y2 = y2;
            tmp.x = x1;
            tmp.k = 0;
            
            e.pb(tmp);
            
            tmp.y1 = y1;
            tmp.y2 = y2;
            tmp.x = x2;
            tmp.k = 1;
            
            e.pb(tmp);
        }
        
        sort(all(e),cmp);
        
        rep(i,sz(e)-1)
        {
            //sub
            if(e[i].k == 0)
                updateTree(1,0,lim,e[i].y1,e[i].y2,1);
            else updateTree(1,0,lim,e[i].y1,e[i].y2,-1);
            
            int ans = getAns(1,0,lim,k);
            
            
        }
    }
    
    return 0;
}

