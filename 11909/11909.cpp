//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 11909 - Soya Milk
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
#define pi acos(-1)/180

using namespace std;

const double conv = acos(-1)/180;
int l,w,h,d;

int main()
{
    freopen("11909.INP","r",stdin);
    freopen("11909.OUT","w",stdout);
    while(scanf(" %d %d %d %d ",&l,&w,&h,&d)==4)
    {
        double V=l*w*h;
        double ex=tan(d*pi)*l;
        double Vex=(l*ex*w)/2;
        double res=V-Vex;
        printf("%.3lf mL\n",res);
    }
    return 0;
}

