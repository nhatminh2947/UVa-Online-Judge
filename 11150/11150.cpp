//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 11150 - Cola
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
    //freopen("11150.INP","r",stdin);
    //freopen("11150.OUT","w",stdout);
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int sum=n;
        while(n>0)
        {
            int brw=0;
            while(n%3)
            {
                brw++;
                n++;
            }
            if(n/3-brw>=0)
                sum+=n/3;
            n=n/3-brw;
        }
        printf("%d\n",sum);
    }
    return 0;
}
