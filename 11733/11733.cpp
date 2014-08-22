//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 11733 - Airport
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
#define maxN 100000
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

int lab[maxN+5];
edge data[maxN+5];
int n,m,a,tcs;

int unionset(int a,int b)
{
    return lab[a]=b;
}

int getRoot(int u)
{
    if(lab[u]==u) return u;
    return lab[u]=getRoot(lab[u]);
}

bool cmp(edge a,edge b)
{
    return a.c<b.c;
}
int main()
{
    freopen("11733.INP","r",stdin);
    freopen("11733.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        scanf(" %d %d %d ",&n,&m,&a);
        int u,v,cost;
        int e=0;
        for(int i=0;i<m;i++)
        {
            scanf(" %d %d %d ",&u,&v,&cost);
            if(cost<a)
            {
                data[e].u=u;
                data[e].v=v;
                data[e++].c=cost;
            }
        }
        
        sort(data,data+e,cmp);
        
        for(int i=1;i<=n;i++)
            lab[i]=i;
        
        cost=0;
        for(int i=0;i<e;i++)
        {
            int r1=getRoot(data[i].u);
            int r2=getRoot(data[i].v);
            int c=data[i].c;
            
            if(r1!=r2)
            {
                cost+=c;
                unionset(r1,r2);
            }
        }
        
        set<int> s;
        for(int i=1;i<=n;i++)
            s.insert(getRoot(i));
        int cnt=s.size();
        
        cost+=cnt*a;
        
        printf("Case %d: %d %d\n",t,cost,cnt);
    }
    return 0;
}
