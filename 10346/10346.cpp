//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Number: 10346 - Peter’s Smokes
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
#define PI 3,1415926535

using namespace std;

int n,k;

int main()
{
    //freopen("10346.INP","r",stdin);
    //freopen("10346.OUT","w",stdout);
    while(scanf(" %d %d ",&n,&k)==2)
    {
        int cnt=n;
        while(n/k!=0)
        {
            int tmp=n/k;
            int a=n%k;
            cnt+=tmp;
            n=n/k+a;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
