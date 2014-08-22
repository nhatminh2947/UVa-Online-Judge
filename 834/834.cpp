//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 834 - Continued Fractions
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

int n,d;

void solve()
{
    swap(n,d);
    while(d!=1)
    {
        printf(",%d",d/n);
        d%=n;
        swap(d,n);
    }
}

int main()
{
    //freopen("834.INP","r",stdin);
    //freopen("834.OUT","w",stdout);
    while(scanf(" %d %d ",&n,&d)==2)
    {
        printf("[");
        if(n==d)
            printf("1");
        else
        {
            printf("%d;",n/d);
            swap(n,d);
            d%=n;
            printf("%d",n/d);
            swap(n,d);
            d%=n;
            solve();
        }
        printf("]\n");
    }
    return 0;
}
