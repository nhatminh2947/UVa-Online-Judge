//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Number: 11626 - Convex Hull
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

typedef struct
{
    double x,y;
}coor;

char v;
coor p[100005],pcmp;
vector<coor> ch;
int tcs,n;

double dist(coor a,coor b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool cmp2(coor a,coor b)
{
    double d1=atan2(a.y-pcmp.y,a.x-pcmp.x);
    double d2=atan2(b.y-pcmp.y,b.x-pcmp.x);
    if(d1==d2)
    {
        if(d1<0)
            return dist(a,pcmp)<dist(b,pcmp);
        return dist(a,pcmp)>dist(b,pcmp);
    }
    return d1<d2;
}

bool cmp1(coor a,coor b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}

int main()
{
    freopen("11626.INP","r",stdin);
    freopen("11626.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int i=0;i<tcs;i++)
    {
        ch.clear();
        scanf(" %d ",&n);
        for(int j=0;j<n;j++)
        {
            scanf(" %lf %lf %c ",&p[i].x,&p[i].y,&v);
            if(v=='Y')
                ch.push_back(p[i]);
        }
        sort(ch.begin(),ch.end(),cmp1);
        pcmp=ch.front();
        sort(ch.begin()+1,ch.end(),cmp2);
        int sz=ch.size();
        printf("%d\n",sz);
        for(int i=0;i<sz;i++)
            printf("%.lf %.lf\n",ch[i].x,ch[i].y);
    }
    return 0;
}
