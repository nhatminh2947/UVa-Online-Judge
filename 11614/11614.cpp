//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 11614 - Etruscan Warriors Never Play Chess
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

double n;
int tcs;

int main()
{
    //freopen("11614.INP","r",stdin);
    //freopen("11614.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=0;t<tcs;t++)
    {
        scanf(" %lf ",&n);
        printf("%.lf\n",floor((-1+sqrt(1+8*n))/2));
    }
    return 0;
}
