//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 532 - Dungeon Master
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

int l,r,c,sl,sr,sc,el,er,ec;
char dungeon[35][35][35];
int step[35][35][35];

int scn()
{
    for(int i=0;i<l;i++)
        for(int j=0;j<r;j++)
            for(int k=0;k<c;k++)
                if(dungeon[i][j][k]=='#')
                    step[i][j][k]=1;
                else if(dungeon[i][j][k]=='.')
                    step[i][j][k]=0;
                else if(dungeon[i][j][k]=='S')
                {
                    step[i][j][k]=1;
                    sl=i;
                    sr=j;
                    sc=k;
                }
                else if(dungeon[i][j][k]=='E')
                {
                    step[i][j][k]=0;
                    el=i;
                    er=j;
                    ec=k;
                }
}

int bfs()
{
    queue< pair< int , pair<int,int> > > q;
    q.push(make_pair(sl,make_pair(sr,sc)));
    int dx[] = { 0, 0, 0, 0,-1, 1};
    int dy[] = { 0, 0,-1, 1, 0, 0};
    int dz[] = {-1, 1, 0, 0, 0, 0};
    while(!q.empty())
    {
        int xx=q.front().second.second;
        int yy=q.front().second.first;
        int zz=q.front().first;
        q.pop();
        for(int i=0;i<6;i++)
        {
            int xxx=xx+dx[i];
            int yyy=yy+dy[i];
            int zzz=zz+dz[i];
            if(0<=xxx && xxx<c && 0<=yyy && yyy<r && 0<=zzz && zzz<l && !step[zzz][yyy][xxx])
            {
                step[zzz][yyy][xxx]=step[zz][yy][xx]+1;
                if(xxx==ec && yyy==er && zzz==el) return step[zzz][yyy][xxx];
                q.push(make_pair(zzz,make_pair(yyy,xxx)));
            }
        }
    }
    return -1;
}

int main()
{
    freopen("532.INP","r",stdin);
    freopen("532.OUT","w",stdout);
    int result;
    while(scanf("%d%d%d ",&l,&r,&c) && l)
    {
        for(int i=0;i<l;i++)
        {
            for(int j=0;j<r;j++)
                gets(dungeon[i][j]);
            scanf(" ");
        }
        scn();
        result=bfs();
        if(result==-1) printf("Trapped!\n");
        else printf("Escaped in %d minute(s).\n",result-1);
    }
    return 0;
}
