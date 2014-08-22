//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 11970 - Lucky Numbers
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
#define INF 1000000000
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)

using namespace std;

int tcs,n;

int main()
{
    //freopen("11970.INP","r",stdin);
    //freopen("11970.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        scanf(" %d ", &n);
        printf("Case %d:",t);
        stack<int> stk;
        for(int i=1;i<=31622 && i*i<n;i++)
        {
            int x=n-i*i;
            if(x%i==0) stk.push(x);
        }
        while(!stk.empty())
        {
            printf(" %d",stk.top());
            stk.pop();
        }
        printf("\n");
    }
    return 0;
}
