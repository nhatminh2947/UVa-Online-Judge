//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 11799 - Horror Dash
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

int main()
{
    //freopen("11799.INP","r",stdin);
    //freopen("11799.OUT","w",stdout);
    int tcs,stu,tmp;
    scanf("%d",&tcs);
    for(int i=1;i<=tcs;i++)
    {
        int max=-INF;
        scanf("%d",&stu);
        for(int j=0;j<stu;j++)
        {
            scanf("%d",&tmp);
            if(max<tmp) max=tmp;
        }
        printf("Case %d: %d\n",i,max);
    }
    return 0;
}
