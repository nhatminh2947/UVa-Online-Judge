//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Number: 278 - Chess
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

int tcs;
char c,m,n;

int main()
{
    //freopen("278.INP","r",stdin);
    //freopen("278.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int i=0;i<tcs;i++)
    {
        scanf(" %c %d %d ",&c,&m,&n);
        if(c=='r' || c=='Q') printf("%d\n",min(m,n));
        else if(c=='k') printf("%d\n",(m*n)/2);
        else if(c=='K')
        {
            if(m%2==1) m++;
            if(n%2==1) n++;
            printf("%d\n",(m*n)/4);
        }
    }
    return 0;
}
