//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Number: 260 - Il Gioco dell'X
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

char board[205][205];
int n,tcs=1;

int dx[]={-1,-1, 0, 0, 1, 1};
int dy[]={-1, 0,-1, 1, 0, 1};

bool in(int x,int y)
{
    return (0<=x && x<n && 0<=y && y<n);
}

char BFS()
{
    queue< pair<int,int> > q;
    for(int i=0;i<n;i++)
        if(board[i][0]=='w')
        {
            board[i][0]='b';
            q.push(make_pair(i,0));
        }
    
    while(!q.empty())
    {
        int y=q.front().first;
        int x=q.front().second;
        if(x==n-1)
            return 'W';
        
        q.pop();
        for(int i=0;i<6;i++)
        {
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(in(xx,yy) && board[yy][xx]!='b')
            {
                board[yy][xx]='b';
                q.push(make_pair(yy,xx));
            }
        }
    }
    return 'B';
}

int main()
{
    //freopen("260.INP","r",stdin);
    //freopen("260.OUT","w",stdout);
    while(scanf(" %d ",&n) && n)
    {
        for(int i=0;i<n;i++)
            gets(board[i]);
        printf("%d %c\n",tcs++,BFS());
    }
    return 0;
}
