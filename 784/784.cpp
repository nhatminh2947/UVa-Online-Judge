//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Number: 784 - Maze Exploration
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

char maze[35][85];
char mark;
int r,c,tcs;

int dx[]={-1, 0, 0, 1};
int dy[]={ 0, 1,-1, 0};

pair<int,int> find()
{
    for(int i=0;i<35;i++)
    {
        for(int j=0;j<85;j++)
        {
            if(maze[i][j]=='*') return make_pair(i,j);
        }
    }
}

void DFS(int x,int y)
{
    maze[y][x]='#';
    for(int i=0;i<4;i++)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(0<=xx && 0<=yy && yy<r && maze[yy][xx]==' ' && maze[yy][xx]!=mark && maze[yy][xx]!='\0')
            DFS(xx,yy);
    }
}

int main()
{
    //freopen("784.INP","r",stdin);
    //freopen("784.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int i=0;i<tcs;i++)
    {
        r=0;
        while(gets(maze[r]) && maze[r][0]!='_')
        {
            r++;
        }
        pair<int,int> coor=find();
        mark=maze[0][0];
        DFS(coor.second,coor.first);
        for(int j=0;j<=r;j++)
            puts(maze[j]);
    }
    return 0;
}
