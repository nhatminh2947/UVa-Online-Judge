//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 12465 - The Turanga Leela Problem
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
    freopen("12465.INP","r",stdin);
    freopen("12465.OUT","w",stdout);
    while(scanf(" %d %d ",&a,&b) && a)
    {
        int cnt=0;
        for(int i=1;i<=b;i++)
            if(a%i == b%i)
                cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}
