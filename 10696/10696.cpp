//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 10696 - f91
//==============================================================

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
#define INF 4294967295

using namespace std;

int f91(int n)
{
    if(n>=101) return n-10;
    else return f91(f91(n+11));
}

int main()
{
    //freopen("10696.INP","r",stdin);
    //freopen("10696.OUT","w",stdout);
    int n;
    while(scanf(" %d ",&n) && n)
    {
        printf("f91(%d) = %d\n",n,f91(n));
    }
    return 0;
}
