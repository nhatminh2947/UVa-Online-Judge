//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 10310 - Dog and Gopher
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

using namespace std;

typedef struct
{
    double x,y;
}coor;

int n;
coor dog,gopher;
coor hole[1005];

double cal(coor a,coor b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main()
{
    //freopen("10310.INP","r",stdin);
    //freopen("10310.OUT","w",stdout);
    while(scanf(" %d ",&n)==1)
    {
        coor res;
        bool lock=false;
        scanf(" %lf %lf %lf %lf ",&gopher.x,&gopher.y,&dog.x,&dog.y);
        for(int i=0;i<n;i++)
            scanf(" %lf %lf ",&hole[i].x,&hole[i].y);
        for(int i=0;i<n;i++)
        {
            double leng=cal(gopher,hole[i]);
            double lend=cal(dog,hole[i])/2;
            if(leng<=lend)
            {
                lock=true;
                res.x=hole[i].x;
                res.y=hole[i].y;
                break;
            }
        }
        if(lock)
            printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n",res.x,res.y);
        else printf("The gopher cannot escape.\n");
    }
    return 0;
}
