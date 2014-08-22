//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number:  11094 - Continents
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

int r,c,cnt;
char maps[25][25];
char land;

int dx[]={ 0, 0,-1, 1};
int dy[]={-1, 1, 0, 0};

int dfs(int x,int y)
{
    maps[y][x]=0;
    for(int i=0;i<4;i++)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx<0) xx=c-1;
        else if(xx>=c) xx=0;
        if(0<=yy && yy<r && maps[yy][xx]==land)
        {
            cnt++;
            dfs(xx,yy);
        }
    }
}
int main()
{
    //freopen("11094.INP","r",stdin);
    //freopen("11094.OUT","w",stdout);
    int x,y;
    while(scanf(" %d %d ",&r,&c)==2)
    {
        for(int i=0;i<r;i++)
            scanf("%s",&maps[i]);
        scanf(" %d %d ",&y,&x);
        cnt=0;
        land=maps[y][x];
        dfs(x,y);
        cnt=0;
        int max=0;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(maps[i][j]==land)
                {
                    cnt=1;
                    dfs(j,i);
                    if(max<cnt) max=cnt;
                }
        printf("%d\n",max);
    }
    return 0;
}
