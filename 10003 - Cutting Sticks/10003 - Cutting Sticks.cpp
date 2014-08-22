//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10003 - Cutting Sticks
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
#include <cctype>
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define maxN 123456
#define INF 1000111222

using namespace std;

int cut[55];
int F[55][55];
int len,n;

int DP(int s,int e)
{
    if(s + 1 == e)
        return 0;
    
    if(F[s][e] != -1)
        return F[s][e];
    
    int m = INF;
    
    for(int i = s+1 ; i < e ; i++)
        m = min(m,DP(s,i) + DP(i,e) + cut[e] - cut[s]);
    
    return F[s][e] = m;
}

int main()
{
    freopen("10003 - Cutting Sticks.INP","r",stdin);
    freopen("10003 - Cutting Sticks.OUT","w",stdout);
    while(scanf(" %d ",&len) && len)
    {
        scanf(" %d ",&n);
        for(int i = 1 ; i <= n ; i++)
            scanf(" %d ",&cut[i]);
        
        cut[0] = 0;
        cut[n+1] = len;
        
        for(int i = 0 ; i <= 51 ; i++)
            for(int j = 0 ; j <= 51 ; j++)
                F[i][j] = -1;
        
        printf("The minimum cutting is %d.\n",DP(0,n+1));
    }
    return 0;
}
