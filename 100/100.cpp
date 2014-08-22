//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 100 - The 3n + 1 problem
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

int solve(long long n)
{
    int cnt=1;
    while(n!=1)
    {
        cnt++;
        if(n%2) n=3*n+1;
        else n/=2;
    }
    return cnt;
}

long long i,j;

int main()
{
    freopen("100.INP","r",stdin);
    freopen("100.OUT","w",stdout);
    while(scanf(" %lld %lld ",&i,&j)!=EOF)
    {
        long long a,b;
        if(i<j)
        {
            a=i;
            b=j;
        }
        else
        {
            a=j;
            b=i;
        }
        int max=-INF;
        for(long long tmp=a;tmp<=b;tmp++)
        {
            int res=solve(tmp);
            if(max<res) max=res;
        }
        printf("%lld %lld %d\n",i,j,max);
    }
    return 0;
}
