//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 785 - Grid Colouring
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
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
using namespace std;

char a[35][85];
bool vis[35][85];
int r;

void init()
{
    for(int i=0;i<r;i++)
    {
        int len=strlen(a[i]);
        for(int j=0;j<len;j++)
            vis[i][j]=false;
    }
}

int dx[]={-1, 0, 0, 1};
int dy[]={ 0,-1, 1, 0};

void DFS(int y,int x,char c)
{
    a[y][x]=c;
    for(int i=0;i<4;i++)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(!vis[yy][xx] && a[yy][xx]==' ')
        {
            vis[yy][xx]=true;
            DFS(yy,xx,c);
        }
    }
}

int main()
{
    freopen("785.INP","r",stdin);
    freopen("785.OUT","w",stdout);
    r=0;
    while(gets(a[r++]))
    {
        while(gets(a[r]) && a[r++][0]!='_');
        
        int len=strlen(a[0]);
        char x;
        for(int i=0;i<len;i++)
            if(a[0][i]!=' ')
            {
                x=a[0][i];
                break;
            }
        init();
        
        for(int i=0;i<r;i++)
        {
            int len=strlen(a[i]);
            for(int j=0;j<len;j++)
                if(!vis[i][j] && a[i][j]!=x && a[i][j]!=' ' && a[i][j]!='_')
                {
                    vis[i][j]=true;
                    DFS(i,j,a[i][j]);
                }
        }
        
        for(int i=0;i<r;i++)
            puts(a[i]);
        
        r=0;
    }
    return 0;
}
