//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1208 - Oreon
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

typedef struct
{
    int u,v,c;
}edge;

int tcs,n;
edge data[1000];
int lab[100];

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

bool cmp2(edge a,edge b)
{
    if(a.c==b.c)
    {
        if(a.u==b.u) return a.v<b.v;
        return a.u<b.u;
    }
    return a.c<b.c;
}

int main()
{
    freopen("1208.INP","r",stdin);
    freopen("1208.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        scanf(" %d ",&n);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int tmp;
                scanf("%d",&tmp);
                getchar();
                if(tmp!=0 && i<j)
                {
                    data[cnt].u=i;
                    data[cnt].v=j;
                    data[cnt++].c=tmp;
                }
            }
        }
        
        for(int i=0;i<n;i++)
            lab[i]=i;
        
        sort(data,data+cnt,cmp);
        
        deque<edge> res;
        
        int done=0;
        for(int i=0;i<cnt;i++)
        {
            int r1=getRoot(data[i].u);
            int r2=getRoot(data[i].v);
            int c=data[i].c;
            
            if(r1!=r2)
            {
                res.push_back(data[i]);
                done++;
                unionset(r1,r2);
            }
            
            if(done==(n-1))
                break;
        }
        
        sort(res.begin(),res.end(),cmp2);
        printf("Case %d:\n",t);
        while(!res.empty())
        {
            printf("%c-%c %d\n",res.front().u+'A',res.front().v+'A',res.front().c);
            res.pop_front();
        }
    }
    return 0;
}
