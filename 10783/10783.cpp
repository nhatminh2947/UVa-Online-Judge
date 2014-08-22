//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 10783 - Odd Sum
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
#define INF 99999999

using namespace std;

int tcs,a,b;

int main()
{
    //freopen("10783.INP","r",stdin);
    //freopen("10783.OUT","w",stdout);
    scanf("%d",&tcs);
    for(int i=1;i<=tcs;i++)
    {
        int odd=0;
        scanf(" %d %d ",&a,&b);
        if(a%2==0) 
            a++;
        for(int j=a;j<=b;j+=2)
            odd+=j;
        printf("Case %d: %d\n",i,odd);
    }
    return 0;
}
