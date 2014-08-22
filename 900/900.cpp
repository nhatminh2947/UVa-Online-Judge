//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 900 - Brick Wall Patterns
// Verdict: Accepted
//******************************************************************
#include <iostream>
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
#define INF 999999999
#define PI 3.1415926535
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
using namespace std;

int n;
long long F[55];

void solve()
{
    F[1]=1;
    F[2]=2;
    for(int i=3;i<=50;i++)
        F[i]=F[i-1]+F[i-2];
}

int main()
{
    //freopen("900.INP","r",stdin);
    //freopen("900.OUT","w",stdout);
    solve();
    while(scanf(" %d ",&n) && n)
    {
        printf("%lld\n",F[n]);
    }
    return 0;
}
