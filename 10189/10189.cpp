//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 10189 - Minesweeper
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
#define INF 99999999

using namespace std;

int main()
{
    //freopen("10189.INP","r",stdin);
    //freopen("10189.OUT","w",stdout);
    int r,c;
    int dx[]={-1,-1,-1, 0, 0, 1, 1, 1};
    int dy[]={ 1, 0,-1, 1,-1, 1, 0,-1};
    char field[105][105];
    int tcs=0;
    while(scanf(" %d %d ",&r,&c) && r)
    {
        if(tcs!=0) printf("\n");
        for(int i=0;i<r;i++)
            gets(field[i]);
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(field[i][j]!='*') field[i][j]='0';
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(field[i][j]=='*')
                {
                    int x=j;
                    int y=i;
                    for(int k=0;k<8;k++)
                        if(0<=x+dx[k] && x+dx[k]<c && 0<=y+dy[k] && y+dy[k]<r && field[y+dy[k]][x+dx[k]]!='*')
                            field[y+dy[k]][x+dx[k]]++;
                }
        printf("Field #%d:\n",++tcs);
        for(int i=0;i<r;i++)
            puts(field[i]);
    }
    return 0;
}
