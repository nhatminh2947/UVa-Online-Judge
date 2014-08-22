//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10077 - The Stern-Brocot Number System
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

struct frac
{
    int x,y;
    frac(int a,int b)
    {
        x=a;
        y=b;
    }
    frac(frac a,frac b)
    {
        x=a.x+b.x;
        y=a.y+b.y;
    }
    frac(){}
};

frac res;

bool check(frac a, frac b)
{
    return (a.x==b.x && a.y==b.y);
}

void BS()
{
    frac lo(0,1);
    frac hi(1,0);
    frac mid(lo,hi);
    
    while(!check(mid,res))
    {
        int m=res.y*mid.x;
        int r=res.x*mid.y;
        if(r>m)
        {
            frac tmp(mid,hi);
            printf("R");
            lo=mid;
            mid=tmp;
        }
        else
        {
            frac tmp(lo,mid);
            printf("L");
            hi=mid;
            mid=tmp;
        }
    }
    printf("\n");
}

int main()
{
    //freopen("10077.INP","r",stdin);
    //freopen("10077.OUT","w",stdout);
    while(scanf(" %d %d ",&res.x,&res.y))
    {
        if(res.x==1 && res.y==1) break;
        BS();
    }
    return 0;
}
