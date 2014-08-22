#include "cstdio"
#include "iostream"
#include "queue"

using namespace std;

int n,m;
char arr[105][105];

int DFS(int x,int y)
{
    arr[x][y]='*';
    for(int i=-1;i<=1;i++)
        for(int j=-1;j<=1;j++)
            if((0<=x+i && x+i<m) && (0<=y+j && y+j<n) && arr[x+i][y+j]=='@')
                DFS(x+i,y+j);
}

int main()
{
    freopen("572.INP","r",stdin);
    freopen("572.OUT","w",stdout);
    while(scanf(" %d %d ",&m,&n) && m)
    {
        int count=0;
        
        for(int i=0;i<m;i++) gets(arr[i]);
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(arr[i][j]=='@')
                {
                    count++;
                    DFS(i,j);
                }
        printf("%d\n",count);
    }
}
