//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 12463 - Little Nephew
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
#define INF 999999999

using namespace std;

int a,b,c,d,e;

int main()
{
    //freopen("12463.INP","r",stdin);
    //freopen("12463.OUT","w",stdout);
    while(scanf(" %d %d %d %d %d ",&a,&b,&c,&d,&e) && a)
    {
        d*=d;
        e*=e;
        int res=a*b*c*d*e;
        printf("%d\n",res);
    }
    return 0;
}
