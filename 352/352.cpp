//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 352 - The Seasonal War
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

int n;
char image[30][30];
int dx[]={-1,-1,-1, 0, 0, 1, 1, 1};
int dy[]={ 1, 0,-1, 1,-1, 1, 0,-1};

int dfs(int x,int y)
{
    image[x][y]='0';
    for(int i=0;i<8;i++)
        if(0<=x+dx[i] && x+dx[i]<n && 0<=y+dy[i] && y+dy[i]<n && image[x+dx[i]][y+dy[i]]=='1')
            dfs(x+dx[i],y+dy[i]);
}

int main()
{
    //freopen("352.INP","r",stdin);
    //freopen("352.OUT","w",stdout);
    int tcs=0;
    while(scanf(" %d ",&n)!=EOF)
    {
        int count=0;
        for(int i=0;i<n;i++)
            scanf(" %s ",&image[i]);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(image[i][j]=='1')
                {
                    count++;
                    dfs(i,j);
                }
        printf("Image number %d contains %d war eagles.\n",++tcs,count);
    }
    return 0;
}
