//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11459 - Snakes and Ladders
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
#define maxN 1000000

int tcs;
int lad[150];
int p[maxN+5];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11459 - Snakes and Ladders.INP","r",stdin);
    freopen("11459 - Snakes and Ladders.OUT","w",stdout);
    #endif
    char inp[100];
    sscanf(gets(inp),"%d",&tcs);
    rep(t,tcs)
    {
        int a,b,c;
        sscanf(gets(inp),"%d %d %d",&a,&b,&c);
        rep(i,110) lad[i] = i;
        rep(i,b)
        {
            int u,v;
            sscanf(gets(inp),"%d %d",&u,&v);
            lad[u] = v;
        }
        rep(i,a) p[i] = 1;
        
        int n = 0;
        bool en = false;
        rep(i,c)
        {
            int r;
            sscanf(gets(inp),"%d",&r);
            if(en) continue;
            
            p[n] = lad[p[n]+r];
            
            if(p[n] >= 100) 
            {
                p[n] = 100;
                en = true;
            }
            n = (n+1)%a;
        }
        
        rep(i,a) printf("Position of player %d is %d.\n",i+1,p[i]);
    }
    

    return 0;
}