//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 591 - Box of Bricks
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

int n;
int h[105];

int main()
{
    //freopen("591.INP","r",stdin);
    //freopen("591.OUT","w",stdout);
    int tcs=0;
    while(scanf(" %d ",&n) && n)
    {
        int sum=0;
        for(int i=0;i<n;i++)
        {
            scanf(" %d ",&h[i]);
            sum+=h[i];
        }
        int avg=sum/n;
        int move=0;
        for(int i=0;i<n;i++)
            if(avg>h[i])
                move+=(avg-h[i]);
        printf("Set #%d\n",++tcs);
        printf("The minimum number of moves is %d.\n\n",move);
    }
    return 0;
}
