//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Number: 11559 - Event Planning
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
#define PI 3.1415926535

using namespace std;

typedef struct
{
    int price;
    int week[15];
}data;

data hotel[20];
int n,b,h,w;

bool cmp(data a,data b)
{
    if(a.price==b.price)
    {
        for(int i=0;i<w;i++)
        {
            if(a.week[i]>n) return a.week[i]>b.week[i];
            if(b.week[i]>n) return b.week[i]>a.week[i];
        }
    }
    return a.price<b.price;
}

int main()
{
    //freopen("11559.INP","r",stdin);
    //freopen("11559.OUT","w",stdout);
    while(scanf(" %d %d %d %d ",&n,&b,&h,&w)==4)
    {
        for(int i=0;i<h;i++)
        {
            scanf(" %d ",&hotel[i].price);
            for(int j=0;j<w;j++)
                scanf(" %d ",&hotel[i].week[j]);
        }
        sort(hotel,hotel+h,cmp);
        bool lock=false;
        int res=INF;
        for(int i=0;i<h && !lock;i++)
        {
            for(int j=0;j<w && !lock;j++)
                if(hotel[i].week[j]>=n && hotel[i].price*n<=b)
                {
                    res=hotel[i].price*n;
                    lock=true;
                }
        }
        if(res==INF) printf("stay home\n");
        else printf("%d\n",res);
        
    }
    return 0;
}
