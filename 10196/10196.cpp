//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10196 - Check The Check
// Verdict:
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
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
using namespace std;

char chess[10][10];
bool K,k;

bool inside(int y,int x)
{
    return (0<=x && x<8 && 0<=y && y<8);
}

void solve(int y,int x,char c)
{
    if(c=='p')
    {
        if(inside(y+1,x-1) && chess[y+1][x-1]=='K') K=true;
        if(inside(y+1,x+1) && chess[y+1][x+1]=='K') K=true;
    }
    else if(c=='P')
    {
        if(inside(y-1,x-1) && chess[y-1][x-1]=='k') k=true;
        if(inside(y-1,x+1) && chess[y-1][x+1]=='k') k=true;
    }
    else if(c=='n' || c=='N')
    {
        int dx[]={-2,-2,-1,-1, 1, 1, 2, 2};
        int dy[]={-1, 1,-2, 2,-2, 2,-1, 1};
        for(int i=0;i<8;i++)
        {
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(inside(yy,xx))
            {
                if(c=='n' && chess[yy][xx]=='K') K=true;
                else if(c=='N' && chess[yy][xx]=='k') k=true;
            }
        }
    }
    else if(c=='b' || c=='B')
    {
        int dx[]={-1,-1, 1, 1};
        int dy[]={-1, 1,-1, 1};
        for(int i=0;i<4;i++)
        {
            int xx=x+dx[i];
            int yy=y+dy[i];
            while(inside(yy,xx))
            {
                if(chess[yy][xx]=='K' && c=='b')
                    K=true;
                else if(chess[yy][xx]=='k' && c=='B')
                    k=true;
                else if(chess[yy][xx]!='.') break;
                xx+=dx[i];
                yy+=dy[i];
            }
        }
    }
    else if(c=='r' || c=='R')
    {
        int dx[]={-1, 0, 0, 1};
        int dy[]={ 0,-1, 1, 0};
        for(int i=0;i<4;i++)
        {
            int xx=x+dx[i];
            int yy=y+dy[i];
            while(inside(yy,xx))
            {
                if(chess[yy][xx]=='K' && c=='r')
                    K=true;
                else if(chess[yy][xx]=='k' && c=='R')
                    k=true;
                else if(chess[yy][xx]!='.') break;
                xx+=dx[i];
                yy+=dy[i];
            }
        }
    }
    else if(c=='q' || c=='Q')
    {
        int dx[]={-1,-1,-1, 0, 0, 1, 1, 1};
        int dy[]={-1, 0, 1,-1, 1,-1, 0, 1};
        for(int i=0;i<8;i++)
        {
            int xx=x+dx[i];
            int yy=y+dy[i];
            while(inside(yy,xx))
            {
                if(chess[yy][xx]=='K' && c=='q')
                    K=true;
                else if(chess[yy][xx]=='k' && c=='Q')
                    k=true;
                else if(chess[yy][xx]!='.') break;
                xx+=dx[i];
                yy+=dy[i];
            }
        }
    }
}

int main()
{
    //freopen("10196.INP","r",stdin);
    //freopen("10196.OUT","w",stdout);
    int tcs=1;
    while(scanf(" %s ",&chess[0]))
    {
        bool lock=false;
        for(int i=1;i<8;i++)
        {
            scanf(" %s ",&chess[i]);
            for(int j=0;j<8 && !lock;j++)
                if(chess[i][j]!='.') lock=true;
        }
        if(!lock) break;
        K=k=false;
        for(int i=0;i<8 && !K && !k;i++)
            for(int j=0;j<8 && !K && !k;j++)
            {
                if(chess[i][j]!='.' && chess[i][j]!='K' && chess[i][j]!='k')
                    solve(i,j,chess[i][j]);
            }
        if(k) printf("Game #%d: black king is in check.\n",tcs++);
        else if(K) printf("Game #%d: white king is in check.\n",tcs++);
        else printf("Game #%d: no king is in check.\n",tcs++);
    }
    return 0;
}
