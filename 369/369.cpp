//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Number: 369 - Combinations
// Verdict: Accepted
//******************************************************************
#include <iostream>
#include <iomanip>
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

double n,m;

int main()
{
    //freopen("369.INP","r",stdin);
    //freopen("369.OUT","w",stdout);
    while(cin>>n>>m && n)
    {
        double a=max(n-m,m);
        double b=min(n-m,m);
        double x=1,y=1;
        for(double i=n;i>a;i--)
            x*=i;
        for(double i=2;i<=b;i++)
            y*=i;
        double c=x/y;
        cout<<n<<" things taken "<<m<<" at a time is "<<fixed<<setprecision(0)<<c<<" exactly."<<endl;
    }
    return 0;
}
