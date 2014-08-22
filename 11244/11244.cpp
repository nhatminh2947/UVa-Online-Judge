//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Number: 11244 - Counting Stars
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

char sky[105][105];
int cnt,star,r,c;

int dx[]={-1,-1,-1, 0, 0, 1, 1, 1};
int dy[]={-1, 0, 1,-1, 1,-1, 0, 1};

int inside(int x,int y)
{
    return (0<=x && x<c && 0<=y && y<r);
}

void DFS(int y,int x)
{
    cnt++;
    sky[y][x]='.';
    for(int i=0;i<8;i++)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(inside(xx,yy) && sky[yy][xx]=='*')
            DFS(yy,xx);
    }
}

int main()
{
    //freopen("11244.INP","r",stdin);
    //freopen("11244.OUT","w",stdout);
    while(scanf(" %d %d ",&r,&c) && r)
    {
        for(int i=0;i<r;i++)
            gets(sky[i]);
        star=0;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
            {
                if(sky[i][j]=='*')
                {
                    cnt=0;
                    DFS(i,j);
                    if(cnt==1) star++;
                }
            }
        printf("%d\n",star);
    }
    return 0;
}
