//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 615 - Is It A Tree?
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
    int u,v;
}edge;

int lab[1000005];
edge data[1000005];
int lv[1000005];
map<int,int> node;

int unionset(int a,int b)
{
    return lab[a]=b;
}

int getRoot(int u)
{
    if(lab[u]==u) return u;
    return lab[u]=getRoot(lab[u]);
}

int main()
{
    freopen("615.INP","r",stdin);
    freopen("615.OUT","w",stdout);
    int tcs=1;
    int u,v;
    while(scanf(" %d %d ",&u,&v) && u!=-1)
    {
        if(u==0 && v==0)
        {
            printf("Case %d is a tree.\n",tcs++);
            continue;
        }
        node.clear();
        int e=1;
        int n=1;
        if(!node[u])
            node[u]=n++;
        
        if(!node[v])
        {
            node[v]=n++;
            lv[node[v]]=0;
        }
        lv[node[v]]++;
        data[e].u=node[u];
        data[e].v=node[v];
        e++;
        while(scanf(" %d %d ",&u,&v) && u)
        {
            if(!node[u])
                node[u]=n++;
        
            if(!node[v])
            {
                node[v]=n++;
                lv[node[v]]=0;
            }
            lv[node[v]]++;
            data[e].u=node[u];
            data[e].v=node[v];
            e++;
        }
        e--;
        n--;
        
        if(e!=(n-1))
        {
            printf("Case %d is not a tree.\n",tcs++);
            continue;
        }
        
        int check=0;
        for(int i=1;i<=n;i++)
        {
            if(lv[i]==0) check++;
            if(check>1) break;
        }
        
        if(check>1)
        {
            printf("Case %d is not a tree.\n",tcs++);
            continue;
        }
        
        for(int i=1;i<=n;i++)
            lab[i]=i;
        
        int cnt=1;
        for(int i=1;i<=e;i++)
        {
            int r1=getRoot(data[i].u);
            int r2=getRoot(data[i].v);
            
            if(r1!=r2)
            {
                unionset(r1,r2);
                cnt++;
            }
        }
        
        if((cnt-1)==e)
            printf("Case %d is a tree.\n",tcs++);
        else 
            printf("Case %d is not a tree.\n",tcs++);
    }
    return 0;
}
