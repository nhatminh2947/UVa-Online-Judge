//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 10018 - Reverse and Add
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

int tcs;

long long reverse(long long n)
{
    long long tmp=n;
    long long m=0;
    while(tmp)
    {
        m=m*10+tmp%10;
        tmp/=10;
    }
    if(m==n) return 0;
    return m;
}

int main()
{
    //freopen("10018.INP","r",stdin);
    //freopen("10018.OUT","w",stdout);
    long long n;
    scanf(" %d ",&tcs);
    for(int i=0;i<tcs;i++)
    {
        int cnt=0;
        scanf(" %lld ",&n);
        while(reverse(n))
        {
            n+=reverse(n);
            cnt++;
        }
        printf("%d %lld\n",cnt,n);
    }
    return 0;
}
