//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Number: 10812 - Beat the Spread!
// Verdict: Accepted
//******************************************************************
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
#define PI 3,1415926535

using namespace std;

int tcs;
int s,d;

int main()
{
    //freopen("10812.INP","r",stdin);
    //freopen("10812.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int i=0;i<tcs;i++)
    {
        scanf(" %d %d ",&s,&d);
        if(s<d || (s+d)%2 || (s-d)%2) printf("impossible\n");
        else
        {
            int x=(s+d)/2;
            int y=(s-d)/2;
            printf("%d %d\n",max(x,y),min(x,y));
        }
    }
    return 0;
}
