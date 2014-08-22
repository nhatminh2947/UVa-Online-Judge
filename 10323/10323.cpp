//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10323 - Factorial! You Must be Kidding!!!
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
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
using namespace std;

int n;

char frac[][11]={"40320",
               "362880",
               "3628800",
               "39916800",
               "479001600",
               "6227020800"};

int main()
{
    //freopen("10323.INP","r",stdin);
    //freopen("10323.OUT","w",stdout);
    while(scanf(" %d ",&n)==1)
    {
        if((n>=0 && n<8) || (n<0 && abs(n%2)==0))
            printf("Underflow!\n");
        else if(n>13 || (n<0 && abs(n%2)==1))
            printf("Overflow!\n");
        else printf("%s\n",frac[n-8]);
    }
    return 0;
}
