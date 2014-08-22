#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#define INF 1000000001

using namespace std;

/*int backtrack(int i,int c)
{
    if(i==1)
    {
        for(int k=1;k<=6;k++)
            if(up[i][k]==c) return 1;
        return 0;
    }
    else
    {
        int m=0;
        if(c==-1)
        {
            for(int k=0;k<=6;k++)
                m=max(backtrack(i-1,down[i][k]),m);
            return m;
        }
        else
        {
            for(int k=1;k<=6;k++)
                if(up[i][k]==c) m=max(backtrack(i-1,down[i][k])+1,m);
            m=max(backtrack(i-1,c),m);
            return m;
        }
    }
}*/

int DP[505][105];
int Pos[505][105];
int n;
int cubes[505][10];
string face[]={"","front","back","left","right","top","bottom"};

void solve()
{
    int down[10]={-1,2,1,4,3,6,5};
    
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=100;j++)
        {
            DP[i][j]=0;
            Pos[i][j]=0;
        }
    
    for(int i=n;i>=1;i--)
    {
        for(int c=1;c<=100;c++)
            DP[i][c]=DP[i+1][c];
        for(int k=1;k<=6;k++)
        {
            int c_up=cubes[i][k];
            int c_down=cubes[i][down[k]];
            if(DP[i+1][c_up]+1>DP[i][c_down])
            {
                DP[i][c_down]=DP[i+1][c_up]+1;
                Pos[i][c_down]=down[k];
            }
        }
    }
    
    int res=-INF;
    int p,f;
    for(int i=1;i<=100;i++)
        if(res<DP[1][i])
        {
            res=DP[1][i];
            p=i;
        }
    
    printf("%d\n",res);
    
    for(int i=1;i<=n;i++)
    {
        if(Pos[i][p]>0)
        {
            cout<<i<<" "<<face[Pos[i][p]]<<endl;
            p=cubes[i][Pos[i][p]%2?Pos[i][p]+1:Pos[i][p]-1];
        }
    }
}

int main()
{
    //freopen("10051.INP","r",stdin);
    //freopen("10051.OUT","w",stdout);
    int t=0;
    while(scanf(" %d ",&n) && n)
    {
        if(t) printf("\n");
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=6;j++)
                scanf(" %d ",&cubes[i][j]);
        }
        printf("Case #%d\n",++t);
        solve();
    }
    return 0;
}
