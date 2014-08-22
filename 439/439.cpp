//==============================================================
// Name: Huynh Nhat Minh
// Problem Number: 439-Knight Moves
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


char s[10];

int nx[]={1,1,-1,-1,2,2,-2,-2};
int ny[]={2,-2,2,-2,1,-1,1,-1};

int bfs(int x1,int y1,int x2,int y2)
{
    if(x1==x2 && y1==y2) return 0;
    queue< pair<int,int> > q;
    q.push(make_pair(x1,y1));
    int x,y,step=0;
    int count[10][10];
    bool check[10][10];
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
        {
            count[i][j]=0;
            check[i][j]=false;
        }
    while(!q.empty())
    {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        for(int i=0;i<8;i++)
        {
            if(x+nx[i]>=1 && x+nx[i]<=8 && y+ny[i]>=1 && y+ny[i]<=8 && check[x+nx[i]][y+ny[i]]==false)
            {
                check[x+nx[i]][y+ny[i]]=true;
                count[x+nx[i]][y+ny[i]]=count[x][y]+1;
                if(x+nx[i]==x2 && y+ny[i]==y2) return count[x+nx[i]][y+ny[i]];
                q.push(make_pair(x+nx[i],y+ny[i]));
            }
        }
    }
    return 0;
}



int main()
{
    //freopen("439.INP","r",stdin);
    //freopen("439.OUT","w",stdout);
    char xx1,xx2;
    int x1,y1,x2,y2;
    while(gets(s))
    {
        sscanf(s,"%c%d %c%d",&xx1,&y1,&xx2,&y2);
        x1=xx1-'a'+1;
        x2=xx2-'a'+1;
        printf("To get from %c%d to %c%d takes %d knight moves.\n",xx1,y1,xx2,y2,bfs(x1,y1,x2,y2));
    }
    return 0;
}
