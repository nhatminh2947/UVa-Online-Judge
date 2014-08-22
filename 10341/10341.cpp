//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10341 - Solve It
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
#define INF 1000000000
#define PI 3.1415926535897932384626433832795
#define E 2,71828183
#define eps 1e-9
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)

using namespace std;

double p,q,r,s,t,u;

double cal(double x)
{
    return (p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u);
}

double BS()
{
    double low=0,high=1;
    double mid;
    for(int i=0;i<25;i++)
    {
        mid=(low+high)/2.0;
        
        double k=cal(mid);
        
        if(k*cal(low)<=0)
            high=mid;
        else low=mid;
    }
    printf("%.4lf\n",mid);
}

int main()
{
    //freopen("10341.INP","r",stdin);
    //freopen("10341.OUT","w",stdout);
    while(scanf(" %lf %lf %lf %lf %lf %lf ",&p,&q,&r,&s,&t,&u)==6)
    {
        if(cal(0)*cal(1)>0)
        {
            printf("No solution\n");
            continue;
        }
        BS();
    }
    return 0;
}
