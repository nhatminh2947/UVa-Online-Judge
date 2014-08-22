//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11402 - Ahoy, Pirates
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

char inp[1000];
int a[2000000];
int n,m,q;
int treeAns[5000000];
int treeStt[5000000];

int buildAns(int node, int lf, int rg)
{
    //printf("node = %d lf = %d rg = %d\n",node,lf,rg);
    treeStt[node] = 0;
    if(lf == rg) return treeAns[node] = a[lf];
    
    int u = buildAns(node*2,lf,(lf+rg)/2);
    int v = buildAns(node*2+1,(lf+rg)/2+1,rg);
    
    //treeMut[node] = 0;
    //treeInv[node] = 0;
    return treeAns[node] = u+v;
}

void inverseAns(int node, int lf, int rg, int LF, int RG)
{
    if(rg < LF || RG < lf)
        return;
    
    if(LF <= lf && rg <= RG)
    {
        if(treeStt[node] == 0)
            treeStt[node] = 1;
        else if(treeStt[node] == 1)
            treeStt[node] = 0;
        else if(treeStt[node] == 2)
            treeStt[node] = 3;
        else if(treeStt[node] = 3)
            treeStt[node] = 2;
        return;
    }
    
    inverseAns(node*2,lf,(lf+rg)/2,LF,RG);
    inverseAns(node*2+1,(lf+rg)/2+1,rg,LF,RG);
   
    return;
}

void mutateAns(int node, int lf, int rg, int LF, int RG, int val)
{
    if(rg < LF || RG < lf)
        return;
    
    if(LF <= lf && rg <= RG)
    {
        treeStt[node] = val;
        return;
    }
    
    mutateAns(node*2,lf,(lf+rg)/2,LF,RG,val);
    mutateAns(node*2+1,(lf+rg)/2+1,rg,LF,RG,val);
    
    return;
}

int getAns(int node, int lf, int rg, int LF, int RG)
{
    printf("node = %d lf = %d rg = %d LF = %d RG = %d stt = %d\n",node,lf,rg,LF,RG,treeStt[node]);
    if(rg < LF || RG < lf)
        return -1;
    
    if(LF <= lf && rg <= RG)
    {
        //cout << "AAA" << endl;
        if(treeStt[node] == 0)
            return treeAns[node];
        if(treeStt[node] == 1)
            return rg - lf + 1 - treeAns[node];
        if(treeStt[node] == 2)
            return 0;
        if(treeStt[node] == 3)
            return rg - lf + 1;
    }
    
    int mid = (lf+rg)/2;
    int u = getAns(node*2,lf,mid,LF,RG);
    int v = getAns(node*2+1,mid+1,rg,LF,RG);
    
    if(treeStt[node] == 0)
    {
        if(u == -1) return v;
        if(v == -1) return u;
        return u+v;
    }
    
    if(treeStt[node] == 2)
    {
        
    }
    
    if(treeStt[node] == 1)
    {
        return mid - lf + 1 - u + rg - mid - 1 + 1 - v;
    }
    
    if(treeStt[node] == 3)
    {
        return rg - lf + 1;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11402 - Ahoy, Pirates.INP","r",stdin);
    freopen("11402 - Ahoy, Pirates.OUT","w",stdout);
    #endif
    
    int tcs;
    sscanf(gets(inp),"%d",&tcs);
    
    fr(t,1,tcs)
    {
        printf("Case %d:\n",t);
        
        n = 0;
        
        sscanf(gets(inp),"%d",&m);
        
        rep(i,m)
        {
            string s;
            int times;
            sscanf(gets(inp),"%d",&times);
            read(s);
            getchar();
            
            rep(j,times)
            {
                rep(k,sz(s))
                    a[++n] = s[k] - '0';
            }
        }
        
        //fr(i,1,n) printf("%d",a[i]);
        //printf("\n");
        buildAns(1,1,n);
        sscanf(gets(inp),"%d",&q);
        int cnt = 1;
        rep(i,q)
        {
            char c;
            int u,v;
            
            sscanf(gets(inp),"%c%d%d",&c,&u,&v);
            u++;
            v++;
            if(c == 'F')
            {
                mutateAns(1,1,n,u,v,3);
            }
            else if(c == 'E')
            {
                mutateAns(1,1,n,u,v,2);
            }
            else if(c == 'I')
            {
                inverseAns(1,1,n,u,v);
            }
            else
            {
                printf("u = %d v = %d\n",u,v);
                printf("Q%d: %d\n",cnt++,getAns(1,1,n,u,v));
            }
            //fr(i,1,n) printf("%d",a[i]);
            //printf("\n");
        }
        
    }
    
    
    return 0;
}
