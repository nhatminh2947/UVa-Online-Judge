//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10879 - Code Refactoring
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

int n,tcs;

int main()
{
    //freopen("10879.INP","r",stdin);
    //freopen("10879.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        scanf(" %d ",&n);
        printf("Case #%d: %d =",t,n);
        int cnt=0;
        for(int i=2;i<=10000000 && cnt!=2;i++)
        {
            if(n%i==0)
            {
                if(cnt) printf(" = ");
                printf(" %d * %d",i,n/i);
                cnt++;
            }
        }
        printf("\n");
    }
    return 0;
}
