//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code:
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

int tcs;
int n,k;
int data[105][105];
bool vis[105][105];
int dist[105][105];

int dx[]={-1, 0, 0, 1};
int dy[]={ 0,-1, 1, 0};

bool inside(int y,int x)
{
    return (0<=x && x<n && 0<=y && y<n);
}

int dij()
{
    int m=-INF;
    set< pair<int,pair<int,int> > > s;
    
    s.insert(make_pair(data[0][0],make_pair(0,0)));
    
    while(!s.empty())
    {
        pair<int,pair<int,int> > tmp=*s.begin();
        int y=tmp.second.first;
        int x=tmp.second.second;
        int dis=tmp.first;
        m=max(m,dis);
        vis[y][x]=true;
        s.erase(tmp);
        
        for(int j=1;j<=k;j++)
        {
            for(int i=0;i<4;i++)
            {
                int yy=y+j*dy[i];
                int xx=x+j*dx[i];
                    
                if(inside(yy,xx) && data[y][x]<data[yy][xx] && dis+data[yy][xx]>dist[yy][xx])
                {
                    if(dist[yy][xx]!=INF) s.erase(make_pair(dist[yy][xx],make_pair(yy,xx)));
                    dist[yy][xx]=dis+data[yy][xx];
                    s.insert(make_pair(dist[yy][xx],make_pair(yy,xx)));
                }
            }
        }
    }
    
    return m;
}

int main()
{
    //freopen("10259.INP","r",stdin);
    //freopen("10259.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        if(t!=1) printf("\n");
        scanf(" %d %d ",&n,&k);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                dist[i][j]=-INF;
                vis[i][j]=false;
                int tmp;
                scanf(" %d ",&tmp);
                data[i][j]=tmp;
            }
            
        int res=dij();
        printf("%d\n",res);
    }
    return 0;
}
