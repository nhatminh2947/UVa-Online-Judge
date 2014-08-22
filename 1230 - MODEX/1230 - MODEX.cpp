//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1230 - MODEX
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
#define int64 long long

using namespace std;

int tcs;

int64 solve(int64 x, int64 y, int64 n)
{
    if(y == 1)
        return x%n;
    
    int64 ans = solve(x,y/2,n);
    
    if(y % 2 == 0)
        return (ans % n) * (ans % n) % n;
        
    return (ans % n) * (ans % n) * (x % n) % n;
}

int main()
{
    freopen("1230 - MODEX.INP","r",stdin);
    freopen("1230 - MODEX.OUT","w",stdout);
    while(scanf(" %d ",&tcs) && tcs)
    {
        for(int t = 0 ; t < tcs ; t++)
        {
            int64 x,y,n;
            scanf(" %lld %lld %lld ",&x,&y,&n);
            
            int64 ans = solve(x,y,n);
            printf("%lld\n",ans);
        }
    }
    return 0;
}
