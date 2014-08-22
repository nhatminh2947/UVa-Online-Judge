//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 11110 - Equidivisions
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

int n,cnt;
int cells[110][110];

int dx[]={-1, 0, 0, 1};
int dy[]={ 0,-1, 1, 0};

int dfs(int x,int y,int c)
{
    cnt++;
    cells[y][x]=0;
    for(int i=0;i<4;i++)
        if(1<=x+dx[i] && x+dx[i]<=n && 1<=y+dy[i] && y+dy[i]<=n && cells[y+dy[i]][x+dx[i]]==c)
            dfs(x+dx[i],y+dy[i],c);
}

int main()
{
    //freopen("11110.INP","r",stdin);
    //freopen("11110.OUT","w",stdout);
    char num[1000];
    while(scanf("%d",&n) && n)
    {
        int x=0,y=0;
        bool lock=false;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                cells[i][j]=n;
        getchar();
        for(int i=1;i<=n-1;i++)
        {
            gets(num);
            int tmp=0;
            while(tmp<strlen(num))
            {
                int count=2;
                sscanf(num+tmp," %d %d ",&x,&y);
                cells[y][x]=i;
                while(x)
                {
                    count++;
                    x/=10;
                }
                while(y)
                {
                    count++;
                    y/=10;
                }
                tmp+=count;
            }
        }
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
                if(cells[j][k]!=0)
                {
                    cnt=0;
                    dfs(k,j,cells[j][k]);
                    if(cnt!=n) 
                    {
                        lock=true;
                        break;
                    }
                }
            if(lock==true) break;
        }
        if(lock==true) printf("wrong\n");
        else printf("good\n");
    }
    return 0;
}
