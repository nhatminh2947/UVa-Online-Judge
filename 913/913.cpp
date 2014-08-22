//**********************************************
// Coded by: Huynh Nhat Minh
// Problem Number: 913 - Joana and the Odd Numbers
// Verdict: Accepted
//**********************************************
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

long long int n;

int main()
{
    //freopen("913.INP","r",stdin);
    //freopen("913.OUT","w",stdout);
    while(scanf(" %lld ",&n)==1)
    {
        n++;
        n/=2;
        long long int last=2*n*n-1;
        long long int res=3*last-6;
        printf("%lld\n",res);
    }
    return 0;
}
