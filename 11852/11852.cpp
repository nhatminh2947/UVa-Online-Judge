//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 11852 - Knight's Trip
// Verdict:
//******************************************************************
#include <iostream>
#include <iomanip>
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
#define INF 1000000000
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)

using namespace std;

const int maxN=10000;

char inp[5];
vector< vector<int> > step;


int dx[]={-2,-2,-1,-1, 1, 1, 2, 2};
int dy[]={-1, 1,-2, 2,-2, 2,-1, 1};

bool inside(int y,int x)
{
    return (0<=x && x<maxN && 0<=y && y<maxN);
}

void BFS()
{
    for(int i=0;i<maxN;i++)
    {
        vector<int> v;
        for(int j=0;j<maxN;j++)
            v.push_back(INF);
        step.push_back(v);    
        
    }
    step[0][0]=0;
    queue< pair<int,int> > q;
    q.push(make_pair(0,0));
    while(!q.empty())
    {
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        for(int i=0;i<maxN;i++)
        {
            int yy=y+dy[i];
            int xx=x+dx[i];
            if(inside(yy,xx) && step[yy][xx]==INF)
            {
                step[yy][xx]=step[y][x]+1;
                q.push(make_pair(yy,xx));
            }
        }
    }
}

int main()
{
    freopen("11852.INP","r",stdin);
    freopen("11852.OUT","w",stdout);
    BFS();
    
    for(int i=maxN-1;i>=0;i--)
    {
        for(int j=0;j<maxN;j++)
            printf("%3d",step[i][j]);
        printf("\n");
    }
    /*while(gets(inp) && inp[0]!='E')
    {
        int x,y;
        sscanf(inp,"%d %d",&x,&y);
        printf("%d\n",step[y][x]);
    }*/
    return 0;
}
