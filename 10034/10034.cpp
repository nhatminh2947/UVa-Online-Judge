//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 10034 - Freckles
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
    float x,y;
}coordinates;

typedef struct
{
    int u,v;
    float c;
}edge;

edge save[100000];
coordinates fre[105];
int lab[105];
int tcs,n;

bool cmp(edge a,edge b)
{
    return a.c<b.c;
}

int getRoot(int u)
{
    if(lab[u]==u) return u;
    return lab[u]=getRoot(lab[u]);
}

int unionset(int a,int b)
{
    return lab[a]=b;
}

int main()
{
    //freopen("10034.INP","r",stdin);
    //freopen("10034.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int i=1;i<=tcs;i++)
    {
        scanf("%d",&n);
        for(int j=0;j<n;j++)
            scanf(" %f %f ",&fre[j].x,&fre[j].y);
        for(int j=0;j<n;j++)
            lab[j]=j;
        int cnt=0;
        for(int j=0;j<n-1;j++)
            for(int k=j+1;k<n;k++)
            {
                save[cnt].u=j;
                save[cnt].v=k;
                save[cnt].c=sqrt((fre[j].x-fre[k].x)*(fre[j].x-fre[k].x)+(fre[j].y-fre[k].y)*(fre[j].y-fre[k].y));
                cnt++;
            }
        sort(save,save+cnt,cmp);
        float cost=0;
        int M=0;
        for(int j=0;j<cnt;j++)
        {
            int u=save[j].u;
            int v=save[j].v ;
            
            int r1=getRoot(u);
            int r2=getRoot(v);
            
            if(r1!=r2)
            {
                unionset(r1,r2);
                cost+=save[j].c;
                M++;
            }
            if(M==(n-1)) break;
        }
        printf("%.2f\n",cost);
        if(i!=tcs) printf("\n");
    }
    return 0;
}
