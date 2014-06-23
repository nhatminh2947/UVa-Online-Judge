//**********************************************
// Coded by: Huynh Nhat Minh
// Problem Number: 116 - Unidirectional TSP
// Verdict: Accepted
//**********************************************
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

int m,n,pos;
int data[15][105];
int F[15][105];
int path[15][105];

void DP()
{
    for(int i=0;i<=m;i++)
        for(int j=0;j<=n;j++)
        {
            path[i][j]=INF;
            F[i][j]=INF;
        }
    for(int i=0;i<m;i++)
        F[i][n-1]=data[i][n-1];
    
    for(int j=n-2;j>=0;j--)
        for(int i=0;i<m;i++)
            for(int k=-1;k<=1;k++)
            {
                int r=(i+k+m)%m;
                if(F[i][j]>=data[i][j]+F[r][j+1])
                {
                    if(F[i][j]>data[i][j]+F[r][j+1] || path[i][j]==-1 || path[i][j]>r)
                        path[i][j]=r;
                    F[i][j]=data[i][j]+F[r][j+1];
                }
            }
}

void result()
{
    int res=INF;
    int pos;
    for(int i=0;i<m;i++)
    {
        if(res>F[i][0])
        {
            pos=i;
            res=F[i][0];
        }
    }
    int x=0;
    int y=pos;
    printf("%d",y+1);
    while(path[y][x]!=INF)
    {
        printf(" %d",path[y][x]+1);
        y=path[y][x];
        x++;
    }
    printf("\n%d\n",res);
}

int main()
{
    //freopen("116.INP","r",stdin);
    //freopen("116.OUT","w",stdout);
    while(scanf(" %d %d ",&m,&n)==2)
    {
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                scanf(" %d ",&data[i][j]);
                F[i][j]=INF;
            }
        DP();
        result();
    }
    return 0;
}
