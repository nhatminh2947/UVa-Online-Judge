//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 11494 - Queen
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
#define PI 3.1415926535
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
using namespace std;

int xa,ya,xb,yb;
bool chess[10][10];

int dx[]={-1,-1,-1, 0, 0, 1, 1, 1};
int dy[]={-1, 0, 1,-1, 1,-1, 0, 1};

bool inside(int y,int x)
{
    return (1<=x && x<=8 && 1<=y && y<=8);
}

int main()
{
    //freopen("11494.INP","r",stdin);
    //freopen("11494.OUT","w",stdout);
    while(scanf(" %d %d %d %d ",&xa,&ya,&xb,&yb))
    {
        if(!xa && !xb && !ya && !yb) break;
        if(xa==xb && ya==yb) printf("0\n");
        else
        {
            for(int i=1;i<=8;i++)
                for(int j=1;j<=8;j++)
                    chess[i][j]=false;
            chess[ya][xa]=true;
            for(int i=0;i<8;i++)
            {
                int xx=xa+dx[i];
                int yy=ya+dy[i];
                while(inside(yy,xx))
                {
                    chess[yy][xx]=true;
                    xx+=dx[i];
                    yy+=dy[i];
                }
            }
            if(chess[yb][xb]) printf("1\n");
            else printf("2\n");
        }
    }
    return 0;
}
