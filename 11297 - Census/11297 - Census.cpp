//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11297 - Census
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

ii treeAns[maxN+5];
int a[505][505];
int n,m;

ii buildTree(int node, int lf, int rg, int up, int down, int stt)
{
    //printf("node = %d lf = %d rg = %d up = %d down = %d\n",node,lf,rg,up,down);
    if(lf == rg && up == down)
        return treeAns[node] = mp(a[up][lf],a[up][lf]);
    
    if((lf == rg && stt == 0) || (up == down && stt == 1))
        return buildTree(node,lf,rg,up,down,1-stt);
    
    ii u,v;
    
    if(stt == 0)
    {
        u = buildTree(node*2  ,lf         ,(lf+rg)/2,up,down,1-stt);
        v = buildTree(node*2+1,(lf+rg)/2+1,rg       ,up,down,1-stt);
    }
    else
    {
        u = buildTree(node*2  ,lf,rg,up           ,(up+down)/2,1-stt);
        v = buildTree(node*2+1,lf,rg,(up+down)/2+1,down       ,1-stt);
    }
    
    return treeAns[node] = mp(max(u.ff,v.ff),min(u.ss,v.ss));
}

ii getAns(int node, int lf, int rg, int up, int down, int LF, int RG, int UP, int DOWN, int stt)
{
    if(LF <= lf && rg <= RG && UP <= up && down <= DOWN)
        return treeAns[node];
        
    if(rg < LF || RG < lf || down < UP || DOWN < up)
        return mp(-INF,INF);
    
    if((lf == rg && stt == 0) || (up == down && stt == 1))
        return getAns(node,lf,rg,up,down,LF,RG,UP,DOWN,1-stt);
    
    ii u,v;
    
    if(stt == 0)
    {
        u = getAns(node*2  ,lf         ,(lf+rg)/2,up,down,LF,RG,UP,DOWN,1-stt);
        v = getAns(node*2+1,(lf+rg)/2+1,rg       ,up,down,LF,RG,UP,DOWN,1-stt);
    }
    else
    {
        u = getAns(node*2  ,lf,rg,up           ,(up+down)/2,LF,RG,UP,DOWN,1-stt);
        v = getAns(node*2+1,lf,rg,(up+down)/2+1,down       ,LF,RG,UP,DOWN,1-stt);
    }
    
    return mp(max(u.ff,v.ff),min(u.ss,v.ss));
}

ii updateAns(int node, int lf, int rg, int up, int down, int LF, int RG, int UP, int DOWN, int stt, int val)
{
    if(LF == lf && rg == RG && UP == up && down == DOWN)
        return treeAns[node] = mp(val,val);
        
    if(rg < LF || RG < lf || down < UP || DOWN < up)
        return treeAns[node];
    
    if((lf == rg && stt == 0) || (up == down && stt == 1))
        return updateAns(node,lf,rg,up,down,LF,RG,UP,DOWN,1-stt,val);
    
    ii u,v;
    
    if(stt == 0)
    {
        u = updateAns(node*2  ,lf         ,(lf+rg)/2,up,down,LF,RG,UP,DOWN,1-stt,val);
        v = updateAns(node*2+1,(lf+rg)/2+1,rg       ,up,down,LF,RG,UP,DOWN,1-stt,val);
    }
    else
    {
        u = updateAns(node*2  ,lf,rg,up           ,(up+down)/2,LF,RG,UP,DOWN,1-stt,val);
        v = updateAns(node*2+1,lf,rg,(up+down)/2+1,down       ,LF,RG,UP,DOWN,1-stt,val);
    }
    
    return treeAns[node] = mp(max(u.ff,v.ff),min(u.ss,v.ss));
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11297 - Census.INP","r",stdin);
    freopen("11297 - Census.OUT","w",stdout);
    #endif
    
    while(scanf(" %d %d ",&n,&m) == 2)
    {
        fr(i,1,n)
            fr(j,1,n)
                scanf(" %d ",&a[i][j]);
        
        buildTree(1,1,n,1,n,0);
        //cout << "ok" << endl;
        int q;
        scanf(" %d ",&q);
        
        rep(i,q)
        {
            char c;
            scanf(" %c ",&c);
            
            if(c == 'c')
            {
                int x,y,val;
                scanf(" %d %d %d ",&y,&x,&val);
                a[y][x] = val;
                updateAns(1,1,n,1,n,x,x,y,y,0,val);
            }
            else
            {
                int x1,x2,y1,y2;
                scanf(" %d %d %d %d ",&y1,&x1,&y2,&x2);
                
                ii ans = getAns(1,1,n,1,n,x1,x2,y1,y2,0);
                cout << ans.ff << " " << ans.ss << endl;
            }
        }
    }
    
    return 0;
}
