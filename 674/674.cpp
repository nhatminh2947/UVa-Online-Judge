//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 674 - Coin Change
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

int cc[7500];
int coin[]={1,5,10,25,50};
int n;

void DP()
{
    for(int i=0;i<=7489;i++)
        cc[i]=1;
    for(int i=1;i<=4;i++)
        for(int j=coin[i];j<=7489;j++)
            cc[j] = cc[j] + cc[j-coin[i]];
}

int main()
{
    freopen("674.INP","r",stdin);
    freopen("674.OUT","w",stdout);
    DP();
    while(scanf(" %d ",&n)!=EOF)
    {
        printf("%d\n",cc[n]);
    }
    return 0;
}
