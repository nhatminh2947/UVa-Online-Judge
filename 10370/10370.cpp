//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 10370 - Above Average
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

int tcs,n;
float grade[1005];

int main()
{
    //freopen("10370.INP","r",stdin);
    //freopen("10370.OUT","w",stdout);
    scanf("%d",&tcs);
    for(int i=0;i<tcs;i++)
    {
        float a=0,cnt=0;
        scanf("%d",&n);
        for(int j=0;j<n;j++)
        {
            scanf("%f",&grade[j]);
            a+=grade[j];
        }
        a/=n;
        for(int j=0;j<n;j++)
            if(grade[j]>a)
                cnt++;
        printf("%.3f%%\n",(cnt/n)*100);
    }
    return 0;
}
