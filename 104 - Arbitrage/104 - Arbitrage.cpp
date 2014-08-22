//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 104 - Arbitrage
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

double a[25][25][25];
int path[25][25][25];
int n;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("104 - Arbitrage.INP","r",stdin);
    freopen("104 - Arbitrage.OUT","w",stdout);
    #endif
    
    while(scanf(" %d ",&n) == 1)
    {
        fr(i,1,n) fr(j,1,n)
        {
            fr(k,1,n) a[i][j][k] = 0;
            if(i == j)
                a[i][j][1] = 1.0;
            else scanf(" %lf ",&a[i][j][1]);
            path[i][j][1] = i;
        }
        
        fr(s,2,n)
            fr(k,1,n)
                fr(i,1,n)
                    fr(j,1,n)
                        if(a[i][j][s] < a[i][k][s-1]*a[k][j][1])
                        {
                            a[i][j][s] = a[i][k][s-1]*a[k][j][1];
                            path[i][j][s] = k;
                        }
        
        bool ans = false;
        for(int s = 2 ; s <= n && !ans ; s++)
            for(int i = 1 ; i <= n && !ans ; i++)
                if(a[i][i][s] > 1.01)
                {
                    int step = s;
                    stack<int> stk;
                    int k = i;
                    while(step)
                    {
                        k = path[i][k][step];
                        stk.push(k);
                        step--;
                    }
                    
                    while(!stk.empty())
                    {
                        printf("%d ",stk.top());
                        stk.pop();
                    }
                    printf("%d\n",i);
                    ans = true;
                }
                    
        if(!ans) puts("no arbitrage sequence exists");
    }
    
    return 0;
}
