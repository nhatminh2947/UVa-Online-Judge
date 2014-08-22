//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10908 - Largest Square
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
#define maxN 100000

int n,m,q,r,c;
char a[105][105];

bool inside(int y, int x)
{
    return (0 <= x && x < m && 0 <= y && y < n);
}

bool ok(int i)
{
    int u = r - i;
    int v = r + i;
    int p = c - i;
    int q = c + i;
    //printf("u = %d v = %d p = %d q = %d\n",u,v,p,q);
    if(!inside(u,p) || !inside(u,q) || !inside(v,p) || !inside(v,q))
        return false;
    
    fr(k,u,v) if(a[k][p] != a[r][c] || a[k][q] != a[r][c])
        return false;
    
    fr(k,p,q) if(a[u][k] != a[r][c] || a[v][k] != a[r][c])
        return false;
    
    return true;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10908 - Largest Square.INP","r",stdin);
    freopen("10908 - Largest Square.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    
    fr(t,1,tcs)
    {
        scanf(" %d %d %d ",&n,&m,&q);
        printf("%d %d %d\n",n,m,q);
        
        rep(i,n) scanf("%s",&a[i]);
        
        rep(i,q)
        {
            scanf(" %d %d ",&r,&c);
            if(!inside(r,c))
            {
                puts("0");
                continue;
            }
            int ans = 0;
            while(ok(ans))
                ans++;
            
            printf("%d\n",(ans-1)*2 + 1);
        }
    }
    
    return 0;
}
