//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 10653 - Bombs! NO they are Mines!!
//==============================================================

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

using namespace std;

int r,c,nline,line,nb;
int step[1005][1005];

int bfs(int sx,int sy,int ex,int ey)
{
    queue< pair<int,int> > q;
    q.push(make_pair(sx,sy));
    int dx[]={0,0,-1,1};
    int dy[]={-1,1,0,0};
    int tmpx,tmpy;
    while(!q.empty())
    {
        tmpx=q.front().first;
        tmpy=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int xx=tmpx+dx[i];
            int yy=tmpy+dy[i];
            if(0<=xx && xx<r && 0<=yy && yy<c && !step[xx][yy])
            {
                step[xx][yy]=step[tmpx][tmpy]+1;
                if(xx==ex && yy==ey)
                    return step[xx][yy];
                q.push(make_pair(xx,yy));
            }
        }
    }
    return step[ex][ey];
}

int main()
{
    //freopen("10653.INP","r",stdin);
    //freopen("10653.OUT","w",stdout);
    while(scanf("%d%d",&r,&c) && r)
    {
        int sx,sy,ex,ey;
        for(int i=0;i<=r;i++)
            for(int j=0;j<=c;j++)
                step[i][j]=0;
        scanf("%d",&nline);
        for(int i=0;i<nline;i++)
        {
            scanf("%d%d",&line,&nb);
            for(int j=0;j<nb;j++)
            {
                int tmp;
                scanf("%d",&tmp);
                step[line][tmp]=1;
            }
        }
        scanf("%d%d",&sx,&sy);
        step[sx][sy]=1;
        scanf("%d%d",&ex,&ey);
        printf("%d\n",bfs(sx,sy,ex,ey)-1);
    }
    return 0;
}
