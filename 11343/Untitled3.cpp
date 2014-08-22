//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Number: 11343 - Isolated Segments
// Verdict:
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

const double Eps = 1e-6;
int tcs,n;

typedef struct
{
    double x,y;
}point;

typedef struct
{
    point s,e;
}edge;

edge e[105];
bool check[105];

int extract(point p1,point p2,double a,double b,double c)
{
    a=p1.y-p2.y;
    b=p2.x-p1.x;
    c=-(a*p1.x+b*p1.y);
}

bool intersection(edge a,edge b)
{
    double a1,b1,c1;
    double a2,b2,c2;
    double t1,t2;
    
    extract(a.s,a.e,a1,b1,c1);
    extract(b.s,b.e,a2,b2,c2);
    
    t1=(a.s.x*a2+a.s.y*b2+c2)*(a.e.x*a2+a.e.y*b2+c2);
    t2=(b.s.x*a1+b.s.y*b1+c1)*(b.e.x*a1+b.e.y*b1+c1);
    cout<<fixed<<t1<<" "<<t2<<endl;
    if(abs(t1)<Eps && abs(t2)<Eps)
        return true;
    return false;
}

int iso()
{
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        bool lock=true;
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                bool a=intersection(e[i],e[j]);
                if(a)
                    lock=false;
            }
        }
        if(lock)
            cnt++;
    }
    return cnt;
}

int main()
{
    freopen("11343.INP","r",stdin);
    freopen("11343.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int i=0;i<tcs;i++)
    {
        scanf(" %d ",&n);
        for(int i=0;i<n;i++)
            scanf(" %lf %lf %lf %lf ",&e[i].s.x,&e[i].s.y,&e[i].e.x,&e[i].e.y);
        int res=iso();
        printf("%d\n",res);
    }
    return 0;
}
