//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10912 - Simple Minded Hashing
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

int dp[55][55][10005];
int n,m;

int solve(int i, int c, int sum)
{
    //printf("i = %d c = %d sum = %d\n",i,c,sum);
    if(i == n)
    {
        if(sum == 0)
            return 1;
        return 0;
    }
    
    if(dp[i][c][sum] != -1) return dp[i][c][sum];
    
    int cnt = 0;
    
    for(int k = 'a'+c ; k <= 'z' ; k++)
        cnt += solve(i+1, k - 'a' + 1, sum - (k - 'a' + 1));
        
    return dp[i][c][sum] = cnt;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10912 - Simple Minded Hashing.INP","r",stdin);
    freopen("10912 - Simple Minded Hashing.OUT","w",stdout);
    #endif
    
    int tcs = 0;
    while(read2(n,m) && n)
    {
        fr(i,0,31)
            fr(j,0,31)
                fr(k,0,m)
                    dp[i][j][k] = -1;
        
        printf("Case %d: %d\n",++tcs,solve(0,0,m));
    }
    
    return 0;
}
