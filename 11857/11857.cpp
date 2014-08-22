//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 11857 - Driving Range
// Verdict: Accepted
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

int lab[1000005];
edge data[1000005];
int n,m;

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
    //freopen("11857.INP","r",stdin);
    //freopen("11857.OUT","w",stdout);
    while(scanf(" %d %d ",&n,&m) && n)
    {
        for(int i=0;i<m;i++)
            scanf(" %d %d %d ",&data[i].u,&data[i].v,&data[i].c);
        
        for(int i=0;i<n;i++)
            lab[i]=i;
        
        sort(data,data+m,cmp);
        
        int done=0;
        int range=-INF;
        for(int i=0;i<m;i++)
        {
            int r1=getRoot(data[i].u);
            int r2=getRoot(data[i].v);
            int c=data[i].c;
            
            if(r1!=r2)
            {
                range=max(range,c);
                done++;
                unionset(r1,r2);
            }
            
            if(done==(n-1))
                break;
        }
        
        bool impos=false;
        for(int i=1;i<n;i++)
            if(getRoot(i)!=getRoot(i-1))
            {
                impos=true;
                break;
            }
        if(impos) printf("IMPOSSIBLE\n");
        else printf("%d\n",range);
    }
    return 0;
}
