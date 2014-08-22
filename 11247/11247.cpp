//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 11247 - Income Tax
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

int m,x;

int main()
{
    //freopen("11247.INP","r",stdin);
    //freopen("11247.OUT","w",stdout);
    while(scanf(" %d %d ",&m,&x) && m)
    {
        if(m==1 || x==100 || x==0)
        {
            printf("Not found\n");
            continue;
        }
        long long lim=m-1;
        long long v=(100*lim)/(100-x);
        if((100*lim)%(100-x)==0) v--;
        if(v<m) printf("Not found\n");
        else
        printf("%lld\n",v);
    }
    return 0;
}
