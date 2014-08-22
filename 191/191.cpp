//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 191 - Intersection
//==============================================================

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

coor edge[5],s,e,lt,rb;
int tcs;

double ccw(coor p1,coor p2,coor p3)
{
    return (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x);
}

void init()
{
    edge[0].x=lt.x;
    edge[0].y=rb.y;
    edge[1]=lt;
    edge[2].x=rb.x;
    edge[2].y=lt.y;
    edge[3]=rb;
}

bool check()
{
    bool t;
    double len1,len2,len3,len4;
        
    for(int i=0;i<4;i++)
    {
        len1=ccw(s,e,edge[i]);
        len2=ccw(s,e,edge[(i+1)%4]);
        len3=ccw(edge[i],edge[(i+1)%4],s);
        len4=ccw(edge[i],edge[(i+1)%4],e);
        if((len1<=0 && len2>=0 && len3<=0 && len4>=0) || (len1<=0 && len2>=0 && len3>=0 && len4<=0) || (len1>=0 && len2<=0 && len3<=0 && len4>=0) || (len1>=0 && len2<=0 && len3>=0 && len4<=0))
            return true;
    }
    
    return false;
}

int main()
{
    //freopen("191.INP","r",stdin);
    //freopen("191.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int i=0;i<tcs;i++)
    {
        scanf(" %lf %lf %lf %lf %lf %lf %lf %lf ",&s.x,&s.y,&e.x,&e.y,&lt.x,&lt.y,&rb.x,&rb.y);
        if(lt.x>rb.x)
            swap(lt.x,rb.x);
        if(lt.y<rb.y)
            swap(lt.y,rb.y);
        printf("%lf %lf %lf %lf\n",lt.x,lt.y,rb.x,rb.y);
        init();
        if(check()) printf("T\n");
        else printf("F\n");
    }
    return 0;
}
