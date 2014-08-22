/***********************************************
/ Coded by: Huynh Nhat Minh                    *
/ Problem 10065 - Useless Tile Packers         *
/ Verdict: AC                                  *
/ Algorithm Graham's scan                      *
/ Time Limit 0.02s                             *
/**********************************************/
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

typedef struct
{
    double x,y;
}coor;

coor p[110],cvp[110],flp;
int n,top;

double ccw(coor p1,coor p2,coor p3)
{
    return (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x);
}

double can(coor a,coor b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool cmp(coor a,coor b)
{
    double da,db;
    coor la,lb;
    
    double len=ccw(p[0],a,b);
    
    la.x=a.x-p[0].x;
    la.y=a.y-p[0].y;
    lb.x=b.x-p[0].x;
    lb.y=b.y-p[0].y;
    
    da=atan2(la.y,la.x);
    db=atan2(lb.y,lb.x);
    
    if(len==0) return can(p[0],a)<can(p[0],b);
    return da<db;
}


void Graham()
{
    int pos=0;
    for(int i=1;i<n;i++)
        if((p[i].y<p[pos].y) || (p[i].y==p[pos].y && p[i].x>p[pos].x))
            pos=i;
            
    swap(p[pos],p[0]);
    sort(p+1,p+n,cmp);
    
    cvp[0]=p[n-1];
    cvp[1]=p[0];
    top=1;
    
    for(int i=1;i<n;i++)
    {
        while(ccw(cvp[top],cvp[top-1],p[i])>0 && top>=1)
            top--;
        cvp[++top]=p[i];
    }
}

double area(coor a[],int b)
{
    double s = 0.0;
    for(int i=0; i<b; i++)
        s += (a[(i+1)%b].y * a[i].x - a[(i+1)%b].x * a[i].y);
    return fabs(s)/2.0;
}

int main()
{
    //freopen("10065.INP","r",stdin);
    //freopen("10065.OUT","w",stdout);
    int tcs=0;
    while(scanf(" %d ",&n) && n)
    {
        for(int i=0;i<n;i++)
            scanf(" %lf %lf ",&p[i].x,&p[i].y);
        
        double min=area(p,n);
        Graham();
        double max=area(cvp,top+1);
        
        printf("Tile #%d\n",++tcs);
        printf("Wasted Space = %.2lf %%\n\n",(max-min)/max*100);
        
    }
    return 0;
}
