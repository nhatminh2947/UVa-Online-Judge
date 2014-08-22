//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 11417 - GCD
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

int GCD(int a,int b)
{
    if(a%b==0) return b;
    return GCD(b,a%b);
}

int main()
{
    //freopen("11417.INP","r",stdin);
    //freopen("11417.OUT","w",stdout);

    while(scanf(" %d ",&n) && n)
    {
        int G=0;
        for(int i=1;i<n;i++)
            for(int j=i+1;j<=n;j++)
            {
                int a=i;
                int b=j;
                if(a<b) swap(a,b);
                G+=GCD(a,b);
            }
        printf("%d\n",G);
    }
    return 0;
}
