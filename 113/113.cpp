//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 113 - Power of Cryptography 
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

double n,p;

int main()
{
    //freopen("113.INP","r",stdin);
    //freopen("113.OUT","w",stdout);
    while(scanf(" %lf %lf ",&n,&p)==2)
    {
        printf("%.lf\n",pow(p,(1/n)));
    }
    
    return 0;
}
