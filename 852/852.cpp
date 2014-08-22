//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 852 - Deciding victory in Go
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

typedef struct
{
    char c;
    bool x,o;
}board;

int tcs;
bool vis[10][10];
board data[10][10];

int dx[]={-1, 0, 0, 1};
int dy[]={ 0,-1, 1, 0};

void DFS(int y,int x,char c)
{
    for(int i=0;i<4;i++)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(data[yy][xx].c=='.')
        {
            if(c=='X' && !data[yy][xx].x)
            {
                data[yy][xx].x=true;
                DFS(yy,xx,c);
            }
            else if(c=='O' && !data[yy][xx].o)
            {
                data[yy][xx].o=true;
                DFS(yy,xx,c);
            }
        }
    }
}

int main()
{
    freopen("852.INP","r",stdin);
    freopen("852.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=0;t<tcs;t++)
    {
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
            {
                scanf(" %c ",&data[i][j].c);
                data[i][j].x=data[i][j].o=false;
            }
        
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
            {
                if(data[i][j].c=='X')
                {
                    data[i][j].x=true;
                    DFS(i,j,data[i][j].c);
                }
                else if(data[i][j].c=='O')
                {
                    data[i][j].o=true;
                    DFS(i,j,data[i][j].c);
                }
            }
        int cntx=0,cnto=0;
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
            {
                if(data[i][j].x && data[i][j].o)
                    continue;
                if(data[i][j].x) cntx++;
                else if(data[i][j].o) cnto++;
            }
        
        printf("Black %d White %d\n",cntx,cnto);
    }
    return 0;
}
