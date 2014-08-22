//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code:
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
#define INF 1000000000
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)

using namespace std;

int a,b,c,d,L;

int F(int x)
{
    return a*x*x + b*x + c;
}

int main()
{
    freopen("11934.INP","r",stdin);
    freopen("11934.OUT","w",stdout);
    while(scanf(" %d %d %d %d %d ",&a,&b,&c,&d,&L) && (a || b || c || d || L))
    {
        int cnt=0;
        for(int i = 0 ; i <= L ; i++)
        {
            if(F(i)%d == 0)
                cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
