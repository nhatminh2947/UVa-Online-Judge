//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 12086 - Potentiometers
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
int n;
int a[200005];
int treeAns[maxN+5];

int buildAns(int node, int lf, int rg)
{
    if(lf == rg) return treeAns[node] = a[lf];
    
    int u = buildAns(node*2  ,lf         ,(lf+rg)/2);
    int v = buildAns(node*2+1,(lf+rg)/2+1,rg       );
    
    return treeAns[node] = u + v;
}

int updateAns(int node, int lf, int rg, int pos)
{
    if(lf == rg && rg == pos)
        return treeAns[node] = a[pos];
    
    if(rg < pos || pos < lf)
        return treeAns[node];
    
    int u = updateAns(node*2,lf,(lf+rg)/2,pos);
    int v = updateAns(node*2+1,(lf+rg)/2+1,rg,pos);
    
    return treeAns[node] = u + v;
}

int getAns(int node, int lf, int rg, int LF, int RG)
{
    if(LF <= lf && rg <= RG)
        return treeAns[node];
    
    if(rg < LF || RG < lf)
        return 0;
    
    int u = getAns(node*2,lf,(lf+rg)/2,LF,RG);
    int v = getAns(node*2+1,(lf+rg)/2+1,rg,LF,RG);
    
    return u+v;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("12086 - Potentiometers.INP","r",stdin);
    freopen("12086 - Potentiometers.OUT","w",stdout);
    #endif
    int tcs = 0;
    while(gets(s) && s[0] != '0')
    {
        if(tcs) printf("\n");
        printf("Case %d:\n",++tcs);
        sscanf(s," %d ",&n);
        fr(i,1,n)
        {
            sscanf(gets(s)," %d ",&a[i]);
            //DEBUG(s);
        }
        
        buildAns(1,1,n);
        
        while(gets(s))
        {
            if(s[0] == 'E') break;
            char c;
            int x, y;
            sscanf(s," %c %d %d ",&c,&x,&y);
            
            if(c == 'M')
            {
                printf("%d\n",getAns(1,1,n,x,y));
            }
            else
            {
                a[x] = y;
                updateAns(1,1,n,x);
            }
        }
    }
    
    return 0;
}
