//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 147 - Dollars
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

float n;
int coin[]={2,4,10,20,40,100,200,400,1000,2000};
long long cc[6005];

void DP()
{
    for(int i=0;i<=6000;i++)
        cc[i]=1;
    for(int i=0;i<=9;i++)
        for(int j=coin[i];j<=6000;j++)
            cc[j]+=cc[j-coin[i]];
}

int main()
{
    freopen("147.INP","r",stdin);
    freopen("147.OUT","w",stdout);
    DP();
    while(scanf(" %f ",&n) && n)
    {
        int tmp=(int)(n/0.05+0.5);
        printf("%6.2f%17lld\n",n,cc[tmp]);
    }
    return 0;
}
