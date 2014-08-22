//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Number: 10284 - Chess in FEN
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

char data[70];
char chess[10][10];

bool inside(int y,int x)
{
    return (0<=x && x<8 && 0<=y && y<8);
}

void solve(char piece,int r,int c)
{
    if(piece=='r' || piece=='R')
    {
        int dc[]={-1, 0, 0, 1};
        int dr[]={ 0,-1, 1, 0};
        for(int i=0;i<4;i++)
        {
            int rr=r+dr[i];
            int cc=c+dc[i];
            while(inside(rr,cc) && (chess[rr][cc]==' ' || chess[rr][cc]=='x'))
            {
                chess[rr][cc]='x';
                rr+=dr[i];
                cc+=dc[i];
            }
        }
    }
    else if(piece=='n' || piece=='N')
    {
        int dc[]={-2,-2,-1,-1, 1, 1, 2, 2};
        int dr[]={-1, 1,-2, 2,-2, 2,-1, 1};
        for(int i=0;i<8;i++)
        {
            int rr=r+dr[i];
            int cc=c+dc[i];
            if(inside(rr,cc) && chess[rr][cc]==' ')
                chess[rr][cc]='x';
        }
    }
    else if(piece=='b' || piece=='B')
    {
        int dc[]={-1,-1, 1, 1};
        int dr[]={-1, 1,-1, 1};
        for(int i=0;i<4;i++)
        {
            int rr=r+dr[i];
            int cc=c+dc[i];
            while(inside(rr,cc) && (chess[rr][cc]==' ' || chess[rr][cc]=='x'))
            {
                chess[rr][cc]='x';
                rr+=dr[i];
                cc+=dc[i];
            }
        }
    }
    else if(piece=='q' || piece=='Q')
    {
        int dc[]={-1,-1,-1, 0, 0, 1, 1, 1};
        int dr[]={-1, 0, 1,-1, 1,-1, 0, 1};
        for(int i=0;i<8;i++)
        {
            int rr=r+dr[i];
            int cc=c+dc[i];
            while(inside(rr,cc) && (chess[rr][cc]==' ' || chess[rr][cc]=='x'))
            {
                chess[rr][cc]='x';
                rr+=dr[i];
                cc+=dc[i];
            }
        }
    }
    else if(piece=='k' || piece=='K')
    {
        int dc[]={-1,-1,-1, 0, 0, 1, 1, 1};
        int dr[]={-1, 0, 1,-1, 1,-1, 0, 1};
        for(int i=0;i<8;i++)
        {
            int rr=r+dr[i];
            int cc=c+dc[i];
            if(inside(rr,cc) && chess[rr][cc]==' ')
                chess[rr][cc]='x';
        }
    }
    else if(piece=='p')
    {
        if(inside(r+1,c+1) && chess[r+1][c+1]==' ')
            chess[r+1][c+1]='x';
        if(inside(r+1,c-1) && chess[r+1][c-1]==' ')
            chess[r+1][c-1]='x';
    }
    else if(piece=='P')
    {
        if(inside(r-1,c+1) && chess[r-1][c+1]==' ')
            chess[r-1][c+1]='x';
        if(inside(r-1,c-1) && chess[r-1][c-1]==' ')
            chess[r-1][c-1]='x';
    }
}

void analyze()
{
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            chess[i][j]=' ';
    int len=strlen(data);
    int r=0;
    int c=0;
    for(int i=0;i<len;i++)
    {
        if(('a'<=data[i] && data[i]<='z') || ('A'<=data[i] && data[i]<='Z'))
        {
            chess[r][c]=data[i];
            c++;
        }
        else if('0'<=data[i] && data[i]<='9')
            c+=(data[i]-'0');
        else if(data[i]=='/')
        {
            r++;
            c=0;
        }
    }
}

int main()
{
    //freopen("10284.INP","r",stdin);
    //freopen("10284.OUT","w",stdout);
    while(scanf(" %s ",&data)==1)
    {
        int cnt=0;
        analyze();
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
                if(chess[i][j]!=' ')
                    solve(chess[i][j],i,j);
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
                if(chess[i][j]==' ')
                    cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}
