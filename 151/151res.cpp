//**********************************************
// Coded by: Huynh Nhat Minh
// Problem Number: 151 - Power Crisis
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

int n;
int res[]={0,1,2,3,4,5,6,7,8,9,10,11,12,1,18,10,11,7,17,11,15,29,5,21,13,26,14,
11,23,22,9,73,17,42,7,98,15,61,22,84,24,30,9,38,15,54,27,9,61,38,22,19,178,38,
53,79,68,166,20,9,22,7,21,72,133,41,10,82,92,64,129,86,73,67,19,66,115,52,24,
22,176,10,57,137,239,41,70,60,116,81,79,55,102,49,5,22,54,52,113,15,66};

int main()
{
    //freopen("151.INP","r",stdin);
    //freopen("151.OUT","w",stdout);
    while(scanf(" %d ",&n) && n)
    {
        printf("%d\n",res[n]);
    }
    return 0;
}
