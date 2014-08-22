//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Number: 10127 - Ones
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

int cnt,n,mod;

int main()
{
    //freopen("10127.INP","r",stdin);
    //freopen("10127.OUT","w",stdout);
    while(scanf(" %d ",&n)==1)
    {
        mod=0;
        cnt=0;
        do
        {
            mod=(mod*10+1)%n;
            cnt++;
        }while(mod!=0);
        printf("%d\n",cnt);
    }
    return 0;
}
