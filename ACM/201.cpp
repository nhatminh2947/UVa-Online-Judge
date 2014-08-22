//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Number:
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
#define PI 3,1415926535

using namespace std;

typedef struct
{
    bool u,d,r,l,stay;
}sq;

int n,m,ch,cv;
int cnt[15];
sq data[15][15];

void init()
{
    for(int i=0;i<=n;i++)
    {
        cnt[i]=0;
        for(int j=0;j<=n;j++)
            data[i][j].r=data[i][j].l=data[i][j].u=data[i][j].d=data[i][j].stay=true;
    }
}

void DFS(int y,int x)
{
    data[y][x].stay=false;
    if(x==0 || x==n+1 || y==0 || y==n+1 || ch==0 || cv==0)
    {
        ch=cv=-INF;
        return;
    }
    
    if(data[y][x].l && data[y][x-1].stay)
    {
        DFS(y,x-1);
        
        ch++;
    }
    if(data[y][x].r && data[y][x+1].stay)
    {
        DFS(y,x+1);
        ch++;
    }
    if(data[y][x].u && data[y+1][x].stay)
    {
        DFS(y+1,x);
        cv++;
    }
    if(data[y][x].d && data[y-1][x].stay)
    {
        DFS(y-1,x);
        cv++;
    }
}

int main()
{
    freopen("201.INP","r",stdin);
    freopen("201.OUT","w",stdout);
    int tcs=0;
    while(scanf(" %d %d ",&n,&m)==2)
    {
        if(tcs)
        {
            printf("\n");
            printf("**********************************\n\n");
        }
        init();
        for(int i=1;i<=m;i++)
        {
            int line,p;
            char c;
            scanf(" %c %d %d ",&c,&line,&p);
            if(c=='H')
                data[line-1][p].d=data[line][p].u=false;
            else data[p][line-1].r=data[p][line].l=false;
        }
        
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(data[i][j].stay)
                {
                    ch=cv=1;
                    DFS(i,j);
                    int a=max(ch,cv);
                    if(a>=1)
                        cnt[a]++;
                }
        bool check=false;
        printf("Problem #%d\n\n",++tcs);
        for(int i=1;i<=9;i++)
            if(cnt[i]!=0)
            {
                check=true;
                printf("%d square (s) of size %d\n",cnt[i],i);
            }
        if(!check) printf("No completed squares can be found.\n");
    }
    return 0;
}
