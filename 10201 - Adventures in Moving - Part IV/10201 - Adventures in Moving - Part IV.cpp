//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10201 - Adventures in Moving - Part IV
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
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 100000

char s[1000];
int dist[105];
int price[105];
int dp[105][205];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10201 - Adventures in Moving - Part IV.INP","r",stdin);
    freopen("10201 - Adventures in Moving - Part IV.OUT","w",stdout);
    #endif
    
    int tcs;
    read(tcs);
    getchar();
    getchar();
    
    bool blank = false;
    rep(i,tcs)
    {
        if(i) printf("\n");
        
        int ed;
        sscanf(gets(s),"%d",&ed);
        
        int n = 0;
        dist[0] = 0;
        price[0] = 0;
        while(gets(s) && s[0] != '\0')
        {
            ++n;
            sscanf(s,"%d %d",&dist[n],&price[n]);
        }
        ++n;
        dist[n] = ed;
        price[n] = INF;
        
        for(int i = 0 ; i <= n ; i++)
            for(int j = 0 ; j <= 200 ; j++)
                dp[i][j] = INF;
        
        dp[0][100] = 0;
        for(int i = 1 ; i <= n ; i++)
        {
            int d = dist[i] - dist[i-1];
            for(int j = d ; j <= 200 ; j++)
                dp[i][j-d] = dp[i-1][j];
            for(int j = 1 ; j <= 200 ; j++)
                dp[i][j] = min(dp[i][j], dp[i][j-1] + price[i]);
        }
        
        int ans = INF;
        for(int j = 100 ; j <= 200 ; j++)
            ans = min(ans,dp[n][j]);
        
        if(ans == INF) puts("Impossible");
        else printf("%d\n",ans);
    }
    
    return 0;
}
