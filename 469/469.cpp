//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Number: 469 - Wetlands of Florida
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

char grid[155][155];
bool vis[155][155];
int cnt,tcs,r,c;

int dx[]={-1,-1,-1, 0, 0, 1, 1, 1};
int dy[]={-1, 0, 1,-1, 1,-1, 0, 1};

bool inside(int x,int y)
{
    return (0<=x && x<c && 0<=y && y<r);
}

void DFS(int x,int y)
{
    cnt++;
    vis[y][x]=true;
    for(int i=0;i<8;i++)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(inside(xx,yy) && grid[yy][xx]=='W' && !vis[yy][xx])
            DFS(xx,yy);
    }
}

int main()
{
    //freopen("469.INP","r",stdin);
    //freopen("469.OUT","w",stdout);
    bool enter=false;
    scanf(" %d ",&tcs);
    for(int i=0;i<tcs;i++)
    {
        if(enter) printf("\n");
        enter=true;
        r=0;
        while(gets(grid[r]) && grid[r][0]!='\0')
        {
            if(grid[r][0]!='W' && grid[r][0]!='L')
            {
                c=strlen(grid[0]);
                for(int i=0;i<r;i++)
                    for(int j=0;j<c;j++)
                        vis[i][j]=false;
                int x,y;
                sscanf(grid[r]," %d %d ",&y,&x);
                cnt=0;
                x--;
                y--;
                if(inside(x,y) && grid[y][x]=='W')
                    DFS(x,y);
                printf("%d\n",cnt);
            }
            else r++;
        }
    }
    return 0;
}
