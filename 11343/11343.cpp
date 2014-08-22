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

int tcs,n;

typedef struct
{
    double x,y;
}coor;

typedef struct
{
    coor s,e;
}edge;

edge e[105];
bool check[105];

double ccw(coor p1,coor p2,coor p3)
{
    return (p2.x-p1.x)*(p3.y-p2.y)-(p2.y-p1.y)*(p3.x-p2.x);
}

int iso()
{
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        bool cut=false;
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                double a=ccw(e[i].s, e[i].e, e[j].s);
                double b=ccw(e[i].s, e[i].e, e[j].e);
                double c=ccw(e[j].s, e[j].e, e[i].s);
                double d=ccw(e[j].s, e[j].e, e[i].e);
                if((a*b<0 && c*d<0) || (a*b<0 && c*d==0) || (a*b==0 && c*d<0) || (!a && b && !c && d) || (!a && b && c && !d) || (a && !b && !c && d) || (a && !b && c && !d))
                {
                    cut=true;
                }
                else if((a==0 && b==0 && c==0 & d==0))
                {
                    if((e[i].s.x<=e[j].s.x && e[j].s.x<=e[i].e.x) && (e[i].s.y<=e[j].s.y && e[j].s.y<=e[i].e.y))
                    {    
                        cut=true;
                    }
                    else if((e[i].s.x<=e[j].e.x && e[j].e.x<=e[i].e.x) && (e[i].s.y<=e[j].e.y && e[j].e.y<=e[i].e.y))
                    {
                        cut=true;
                    }
                    else if((e[j].s.x<=e[i].s.x && e[i].s.x<=e[j].e.x) && (e[j].s.y<=e[i].s.y && e[i].s.y<=e[j].e.y))
                    {
                        cut=true;
                    }
                    else if((e[j].s.x<=e[i].e.x && e[i].e.x<=e[j].e.x) && (e[j].s.y<=e[i].e.y && e[i].e.y<=e[j].e.y))
                    {
                        cut=true;
                    }
                }
            }
        }
        if(!cut) cnt++;
    }
    return cnt;
}

int main()
{
    //freopen("11343.INP","r",stdin);
    //freopen("11343.OUT","w",stdout);
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
