//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 11881 - Internal Rate of Return
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
#define E 2,71828183
#define eps 1e-9
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)

using namespace std;

int T[20];
int n;

double f(double irr)
{
    double sum=0;
    double k=1;
    for(int i=0;i<=n;i++)
    {
        sum+=(T[i]/k);
        k*=(1+irr);
    }
    return sum;
}

double BS()
{
    double lo=-1,hi=INF;
    double mid;
    
    for(int i=0;i<50;i++)
    {
        mid=(lo+hi)/2;
        
        double k=f(mid);
        double l=f(lo);
        double h=f(hi);
        
        if(k*l<0 && k*h<0)
            return -INF;
        
        if(k*l>0 && k*h>0)
            return -1;
        
        if(k*l<=0)
            hi=mid;
        else lo=mid;
    }
    
    return mid;
}

int main()
{
    freopen("11881.INP","r",stdin);
    freopen("11881.OUT","w",stdout);
    while(scanf(" %d ",&n) && n)
    {
        for(int i=0;i<=n;i++)
            scanf(" %d ",&T[i]);
        double res=BS();
        if(res==-INF) printf("Too many\n");
        else if(res==-1) printf("No\n");
        else
            printf("%.2lf\n",res);
    }
    return 0;
}
