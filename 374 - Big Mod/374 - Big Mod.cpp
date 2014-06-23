//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 374 - Big Mod
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
#define int64 long long

using namespace std;

int64 solve(int64 b, int64 p, int64 m)
{
    if(p == 1)
        return b%m;
    
    if(p == 0)
        return 1;
    
    int64 tmp = solve(b,p/2,m);
    
    if(p%2 == 0)
        return (tmp%m) * (tmp%m) % m;
    return (tmp%m) * (tmp%m) * (b%m) % m;
}

int main()
{
    freopen("374 - Big Mod.INP","r",stdin);
    freopen("374 - Big Mod.OUT","w",stdout);
    int64 b,p,m;
    while(scanf(" %lld %lld %lld ",&b,&p,&m) == 3)
    {
        int64 res = solve(b,p,m);
        printf("%d\n",res);
    }
    return 0;
}
