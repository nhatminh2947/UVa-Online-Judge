//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Number: 696 - How Many Knights
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
#define PI 3.1415926535

using namespace std;

int m,n,res;

int main()
{
    //freopen("696.INP","r",stdin);
    //freopen("696.OUT","w",stdout);
    while(scanf(" %d %d ",&m,&n) && m)
    {
        if((m==1) || (n==1)) res=m*n;
        else if(m==2 || n==2)
        {
            int t=max(m,n);
            int a=t%4;
            t/=4;
            t*=4;
            if(a==1) t+=2;
            else if(a>1) t+=4;
            res=t;
        }
        else
            res=(m*n+1)/2;
        printf("%d knights may be placed on a %d row %d column board.\n",res,m,n);
    }
    return 0;
}
