//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11550 - Demanding Dilemma
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



int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11550 - Demanding Dilemma.INP","r",stdin);
    freopen("11550 - Demanding Dilemma.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    
    rep(t,tcs)
    {
        int n,m;
        scanf(" %d %d ",&n,&m);
        int edge[50];
        int a[10][50];
        int cnt[10][10];
        
        rep(i,m) edge[i] = 0;
        rep(i,n) rep(j,n) cnt[i][j] = 0;
        
        rep(i,n)
            rep(j,m)
                scanf(" %d ",&a[i][j]);
        bool ok = true;
        rep(j,m)
        {
            int u = -1;
            int v = -1;
            rep(i,n)
            {
                if(a[i][j])
                {
                    if(u == -1) u = i;
                    else v = i;
                }
                edge[j] += a[i][j];
            }
            
            if(edge[j] != 2)
            {
                ok = false;
                break;
            }
            
            cnt[u][v]++;
            
            if(cnt[u][v] != 1)
            {
                ok = false;
                break;
            }
        }
        
        if(ok) puts("Yes");
        else puts("No");
            
    }
    
    return 0;
}
