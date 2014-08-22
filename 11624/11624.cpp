//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Number: 11624 - Fire!
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

char data[1005][1005];
int step[1005][1005];
int tcs,r,c;
bool lock;
pair<int,int> J;

int dx[]={-1, 0, 0, 1};
int dy[]={ 0,-1, 1, 0};

void init()
{
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(data[i][j]=='.')
                step[i][j]=INF;
}

void BFSF()
{
    queue< pair<int,int> > q;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
        {
            if(data[i][j]=='F')
            {
                q.push(make_pair(i,j));
                step[i][j]=0;
            }
            else if(data[i][j]=='J')
            {
                J.first=i;
                J.second=j;
            }
        }
    while(!q.empty())
    {
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(data[yy][xx]=='.' && step[yy][xx]==INF)
            {
                step[yy][xx]=step[y][x]+1;
                q.push(make_pair(yy,xx));
            }
        }
    }
}

int BFSJ()
{
    queue< pair<int,int> > q;
    q.push(J);
    step[J.first][J.second]=0;
    while(!q.empty())
    {
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        if(y==0 || y==r-1 || x==0 || x==c-1) return step[y][x];
        for(int i=0;i<4;i++)
        {
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(data[yy][xx]=='.' && step[yy][xx]>step[y][x]+1)
            {
                step[yy][xx]=step[y][x]+1;
                q.push(make_pair(yy,xx));
            }
        }
    }
    return INF;
}

int main()
{
    //freopen("11624.INP","r",stdin);
    //freopen("11624.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int i=0;i<tcs;i++)
    {
        scanf(" %d %d ",&r,&c);
        for(int j=0;j<r;j++)
            scanf(" %s ",&data[j]);
        init();
        BFSF();
        int res=BFSJ();
        
        if(res==INF) printf("IMPOSSIBLE\n");
        else printf("%d\n",res+1);
    }
    return 0;
}
