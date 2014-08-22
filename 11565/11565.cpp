//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 11565 - Simple Equations
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
#define INF 99999999

using namespace std;

int main()
{
    //freopen("11565.INP","r",stdin);
    //freopen("11565.OUT","w",stdout);
    int tcs,a,b,c;
    scanf("%d",&tcs);
    for(int i=0;i<tcs;i++)
    {
        bool lock=false;
        int x,y,z;
        scanf("%d %d %d",&a,&b,&c);
        for(x=-b;x<=b;x++)
            if(x!=0 && b%x==0)
            {
                for(y=-abs(b/x);y<=abs(b/x);y++)
                    if(y!=0 && y!=x && b%(x*y)==0 && b/(x*y)!=x && b/(x*y)!=y && x+y+b/(x*y)==a && x*x+y*y+(b/(x*y))*(b/(x*y))==c)
                    {
                        z=b/(x*y);
                        lock=true;
                        break;
                    }
                if(lock) break;
            }
        if(lock) printf("%d %d %d\n",x,y,z);
        else printf("No solution.\n");
    }
    return 0;
}
