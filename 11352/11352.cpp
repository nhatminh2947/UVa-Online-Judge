//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 11352 - Crazy King
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

int t,m,n,sx,sy,ex,ey;
char road[105][105];
int step[105][105];

int scn()
{
    int hx[]={-1,-1,1,1,-2,-2,2,2};
    int hy[]={-2,2,-2,2,-1,1,-1,1};
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            step[i][j]=0;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        {
            if(road[i][j]=='Z')
            {
                road[i][j]='X';
                step[i][j]=1;
                for(int k=0;k<8;k++)
                    if(0<=j+hx[k] && j+hx[k]<n && 0<=i+hy[k] && i+hy[k]<m && road[i+hy[k]][j+hx[k]]=='.')
                    {
                        road[i+hy[k]][j+hx[k]]='X';
                        step[i+hy[k]][j+hx[k]]=1;
                    }
            }
            else if(road[i][j]=='A')
            {
                step[i][j]=1;
                sx=j;
                sy=i;
            }
            else if(road[i][j]=='B')
            {
                ex=j;
                ey=i;
            }
        }
}

int bfs()
{
    queue< pair<int,int> > q;
    q.push(make_pair(sx,sy));
    int kx[]={-1,-1,-1, 0,0, 1,1,1};
    int ky[]={-1, 0, 1,-1,1,-1,0,1};
    while(!q.empty())
    {
        int xx=q.front().first;
        int yy=q.front().second;
        q.pop();
        for(int i=0;i<8;i++)
        {
            if(0<=xx+kx[i] && xx+kx[i]<n && 0<=yy+ky[i] && yy+ky[i]<m && !step[yy+ky[i]][xx+kx[i]])
            {
                step[yy+ky[i]][xx+kx[i]]=step[yy][xx]+1;
                if(xx+kx[i]==ex && yy+ky[i]==ey)
                    return step[yy+ky[i]][xx+kx[i]];
                q.push(make_pair(xx+kx[i],yy+ky[i]));
            }
        }
    }
    return -1;
}

int main()
{
    //freopen("11352.INP","r",stdin);
    //freopen("11352.OUT","w",stdout);
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d%d ",&m,&n);
        for(int j=0;j<m;j++)
            gets(road[j]);
        scn();
        int result=bfs();
        
        if(result==-1) printf("King Peter, you can't go now!\n");
        else printf("Minimal possible length of a trip is %d\n",result-1);
    }
    
    return 0;
}
