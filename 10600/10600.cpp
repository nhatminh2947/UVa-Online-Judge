//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 10600 - ACM Contest and Blackout
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

typedef struct
{
    int u,v,c;
}edge;

edge data[6005];
int lab[105];
int tcs,n,m;
bool check[105][105];

int getRoot(int u)
{
    if(lab[u]==u) return u;
    return lab[u]=getRoot(lab[u]);
}

int unionset(int a,int b)
{
    return lab[a]=b;
}

bool cmp(edge a,edge b)
{
    return a.c<b.c;
}

int main()
{
    freopen("10600.INP","r",stdin);
    freopen("10600.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int i=0;i<tcs;i++)
    {
        scanf(" %d %d ",&n,&m);
        for(int j=0;j<m;j++)
            scanf(" %d %d %d ",&data[j].u,&data[j].v,&data[j].c);
        sort(data,data+m,cmp);
        for(int j=1;j<=n;j++)
        {
            lab[j]=j;
            for(int k=1;k<=n;k++)
                check[j][k]=false;
        }
        int done=0;
        int w=0;
        for(int j=0;j<m;j++)
        {
            int u=data[j].u;
            int v=data[j].v;
            int c=data[j].c;
            
            int r1=getRoot(lab[u]);
            int r2=getRoot(lab[v]);
            
            if(r1!=r2)
            {
                check[u][v]=check[v][u]=true;
                unionset(r1,r2);
                w+=c;
                done++;
            }
            if(done==(n-1)) break;
        }
        printf("%d",w);
        int min=INF;
        for(int j=1;j<=n-1;j++)
            for(int k=j+1;k<=n;k++)
            {
                if(check[j][k])
                {
                    for(int p=1;p<=n;p++)
                        lab[p]=p;
                    done=0;
                    w=0;
                    for(int p=0;p<m;p++)
                    {
                        int u=data[p].u;
                        int v=data[p].v;
                        if((u==j && v==k) || (u==k && v==j)) continue;
                        int c=data[p].c;
                        
                        int r1=getRoot(lab[u]);
                        int r2=getRoot(lab[v]);
                        
                        if(r1!=r2)
                        {
                            unionset(r1,r2);
                            w+=c;
                            done++;
                        }
                        if(done==(n-1)) 
                        {
                            if(min>w) min=w;
                            break;
                        }
                    }
                    
                }
            }
        printf(" %d\n",min);
    }
    return 0;
}
