//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 11338 - Minefield
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
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define maxN 123456
#define INF 1000111222

using namespace std;

typedef struct
{
    double x,y;
}point;

int w,h,n;
double lim;
point data[10005];
double dist[10005];

double d(int a,int b)
{
    return sqrt((data[a].x-data[b].x)*(data[a].x-data[b].x) + (data[a].y-data[b].y)*(data[a].y-data[b].y));
}

double dij()
{
    n++;
    data[0].x = 0;
    data[0].y = 0;
    data[n].x = w;
    data[n].y = h;
    for(int i = 0 ; i <= n ; i++)
        dist[i] = INF;
    dist[0] = 0;
    set< pair<double,int> > s;
    s.insert(mp(0,0));
    
    while(!s.empty())
    {
        pair<double,int> tmp = *s.begin();
        s.erase(tmp);
        int pos = tmp.ss;
        double dis = tmp.ff;
        if(pos == n)
            return dis;
        for(int i = 1 ; i <= n ; i++)
        {
            double t = d(pos,i);
            if((dist[i] > t+dis) && t <= 1.5)
            {
                if(dist[i] != INF)
                    s.erase(mp(dist[i],i));
                dist[i] = t + dis;
                s.insert(mp(dist[i],i));
            }
        }
    }
    return INF;
}

int main()
{
    //freopen("11338 - Minefield.INP","r",stdin);
    //freopen("11338 - Minefield.OUT","w",stdout);
    char tmp[10];
    while(scanf(" %s ",&tmp))
    {
        if(tmp[0] == '*')
            break;
        
        w = 0;
        for(int i = 0 ; i < strlen(tmp) ; i++)
            w = w*10 + tmp[i] - '0';
        scanf(" %d ",&h);
        scanf(" %d ",&n);
        for(int i = 1 ; i <= n ; i++)
            scanf(" %lf %lf ",&data[i].x,&data[i].y);
        scanf(" %lf ",&lim);
        double ans = dij();
        if(ans <= lim)
            puts("I am lucky!");
        else puts("Boom!");
    }
    return 0;
}
