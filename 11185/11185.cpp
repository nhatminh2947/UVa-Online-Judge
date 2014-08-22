//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 11185 - Ternary
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

stack<long long> s;
long long n;

int main()
{
    //freopen("11185.INP","r",stdin);
    //freopen("11185.OUT","w",stdout);
    while(scanf("%lld",&n) && n>=0)
    {
        if(n==0) printf("0\n");
        else
        {
            while(n>0)
            {
                s.push(n%3);
                n/=3;
            }
            while(!s.empty())
            {
                printf("%lld",s.top());
                s.pop();
            }
            printf("\n");
        }
    }
    return 0;
}
