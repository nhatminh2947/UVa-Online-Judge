//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Number: 782 - Contour Painting
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

char contour[35][85];
bool vis[35][85];
int tcs,r,c;

int dx[]={-1, 0, 0, 1};
int dy[]={ 0,-1, 1, 0};

void init()
{
    for(int i=0;i<=r;i++)
        for(int j=0;j<=c;j++)
        {
            if(contour[i][j]=='\0' && contour[i][j]!='*' && contour[i][j]!='_')
                contour[i][j]=' ';
            vis[i][j]=false;
        }
}

bool inside(int y,int x)
{
    return (0<=x && x<=c && 1<=y && y<r);
}

void DFS(int y,int x)
{
    int yy,xx;
    for(int i=0;i<4;i++)
    {
        xx=x+dx[i];
        yy=y+dy[i];
        if(inside(yy,xx) && contour[yy][xx]!='#' && contour[yy][xx]!=' ' && contour[yy][xx]!='_')
            contour[y][x]='#';
    }
    for(int i=0;i<4;i++)
    {
        xx=x+dx[i];
        yy=y+dy[i];
        if(!vis[yy][xx] && inside(yy,xx) && contour[yy][xx]==' ')
        {
            vis[yy][xx]=true;
            DFS(yy,xx);
        }
    }
}

void standar()
{
    for(int i=1;i<=r;i++)
    {
        for(int j=c;j>=0;j--)
        {
            if(contour[i][j]==' ')
                contour[i][j]='\0';
            else break;
        }
    }
}

int main()
{
    //freopen("782.INP","r",stdin);
    //freopen("782.OUT","w",stdout);
    scanf("%d",&tcs);
    getchar();
    for(int i=0;i<tcs;i++)
    {
        r=1;
        c=-INF;
        bool lock=false;
        while(gets(contour[r]) && contour[r][0]!='_')
        {
            int len=strlen(contour[r]);
            for(int i=len;i<85;i++)
                contour[r][i]='\0';
            c=max(c,len);
            r++;
        }
        int len=strlen(contour[r]);
        for(int i=len;i<85;i++)
            contour[r][i]='\0';
            
        init();
        
        for(int j=1;j<=r && !lock;j++)
            for(int k=0;k<=c && !lock;k++)
                if(contour[j][k]=='*')
                {
                    contour[j][k]=' ';
                    vis[j][k]=true;
                    DFS(j,k);
                    lock=true;
                }
                
        standar();
        
        for(int j=1;j<=r;j++)
            puts(contour[j]);
    }
    return 0;
}
