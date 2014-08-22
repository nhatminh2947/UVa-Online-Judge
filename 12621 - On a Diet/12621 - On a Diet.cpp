//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 12621 - On a Diet
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

int a[105];
int n,p;
int ans;
int DP[105][30005];

/*
void solve(int i, int sum)
{
    if(i == 1)
    {
        if(a[i] <= sum) return a[i];
        return 0;
    }
    
    int tmp = solve(i-1,sum);
    
    if(a[i] <= sum)
        return max(tmp,solve(i-1,sum - a[i]) + a[i]);
    
    return tmp;
}*/

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("12621 - On a Diet.INP","r",stdin);
    freopen("12621 - On a Diet.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    rep(t,tcs)
    {
        ans = INF;
        scanf(" %d %d ",&n,&p);
        n /= 10;
        
        int s = 0;
        fr(i,1,p) 
        {
            scanf(" %d ",&a[i]);
            a[i] /= 10;
            s += a[i];
        }
        
        if(s < n)
        {
            puts("NO SOLUTION");
            continue;
        }
        
        //solve(p,s);
        //sort(a+1,a+p+1);
        for(int i = 0 ; i <= n+1000 ; i++)
            DP[1][i] = (a[1] <= i) ? a[1] : 0;
        
        int ans = INF;
        for(int i = 2 ; i <= p ; i++)
            for(int j = 0 ; j <= n + 1000 ; j++)
                if(a[i] <= j)
                {
                    DP[i][j] = max(DP[i-1][j],DP[i-1][j-a[i]] + a[i]);
                    if(DP[i][j] >= n)
                        ans = min(ans,DP[i][j]);
                }
                else DP[i][j] = DP[i-1][j];
                
        cout << ans*10 << endl;
        
    }

    return 0;
}