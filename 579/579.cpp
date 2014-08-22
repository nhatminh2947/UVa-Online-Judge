//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 579 - ClockHands
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

int main()
{
    //freopen("579.INP","r",stdin);
    //freopen("579.OUT","w",stdout);
    char time[10];
    float h,m;
    float d;
    while(scanf(" %s ",&time))
    {
        sscanf(time," %f:%f ",&h,&m);
        if(h==0 && m==0) break;
        h=h*5+(m/12);
        d=abs(h-m)*6;
        if(d>180) d=360-d;
        printf("%.3f\n",d);
    }
    return 0;
}
