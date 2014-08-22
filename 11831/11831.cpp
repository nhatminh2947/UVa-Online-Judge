//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Number: 11831 - Sticker Collector Robots
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
    char d;
    int x,y;
}robot;

robot r;
int n,m,s;
char instruct;
char data[105][105];
pair<int,int> d[5];

void direct()
{
    d[0]=make_pair(-1, 0);//N
    d[1]=make_pair( 0, 1);//L
    d[2]=make_pair( 1, 0);//S
    d[3]=make_pair( 0,-1);//O
}

bool inside(int y,int x)
{
    return (0<=y && y<n && 0<=x && x<m);
}

int main()
{
    //freopen("11831.INP","r",stdin);
    //freopen("11831.OUT","w",stdout);
    direct();
    while(scanf(" %d %d %d ",&n,&m,&s) && n)
    {
        for(int i=0;i<n;i++)
            scanf(" %s ",&data[i]);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(data[i][j]!='.' && data[i][j]!='*' && data[i][j]!='#')
                {
                    if(data[i][j]=='N')
                        r.d=0;
                    else if(data[i][j]=='L')
                        r.d=1;
                    else if(data[i][j]=='S')
                        r.d=2;
                    else if(data[i][j]=='O')
                        r.d=3;
                    r.y=i;
                    r.x=j;
                    data[i][j]='.';
                }
            }
        
        int cnt=0;
        for(int i=0;i<s;i++)
        {
            scanf(" %c ",&instruct);
            if(instruct=='D') r.d=(r.d+1)%4;
            else if(instruct=='E') r.d=(r.d-1+4)%4;
            else if(instruct=='F')
            {
                int xx=r.x+d[r.d].second;
                int yy=r.y+d[r.d].first;
                if(data[yy][xx]!='#' && inside(yy,xx))
                {
                    r.y=yy;
                    r.x=xx;
                    if(data[r.y][r.x]=='*')
                    {
                        data[r.y][r.x]='.';
                        cnt++;
                    }
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
