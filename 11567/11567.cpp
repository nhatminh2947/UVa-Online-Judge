//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number:  11567 - Moliu Number Generator
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
    freopen("11567.INP","r",stdin);
    freopen("11567.OUT","w",stdout);
    int n;
    while (scanf("%lld",&n)!=EOF)
    {
        int count = 0;
        while (n > 0)
        {
            if (n % 2 == 0)
                n/=2, count++;
            else 
            {
                if ((n+1)% 4 == 0 && n >= 4)
                    count++, n++;
                else 
                    count++, n--;
            }
                
        }
        printf("%d\n",count);
    }
    return 0;
}
