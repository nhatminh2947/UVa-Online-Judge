//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 12468 - Zapping
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

int a,b;

int main()
{
    //freopen("12468.INP","r",stdin);
    //freopen("12468.OUT","w",stdout);
    while(scanf(" %d %d ",&a,&b) && a!=-1)
    {
        int cnt=0;
        if(a>b) swap(a,b);
        int ans=min(abs(a-b),abs(a+100-b));
        printf("%d\n",ans);
    }
    return 0;
}
