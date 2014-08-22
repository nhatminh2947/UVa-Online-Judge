//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 11710 - Expensive subway
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
    string u,v;
    int c;
}edge;

map<string,int> sub;
string start;
string place[405];
int s,c;
int lab[405];
edge data[79805];

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
    //freopen("11710.INP","r",stdin);
    //freopen("11710.OUT","w",stdout);
    while(scanf(" %d %d ",&s,&c) && s)
    {
        for(int i=1;i<=s;i++)
        {
            cin>>place[i];
            sub[place[i]]=i;
            lab[i]=i;
        }
        
        for(int i=0;i<c;i++)
            cin>>data[i].u>>data[i].v>>data[i].c;
        
        cin>>start;
        
        sort(data,data+c,cmp);
        
        int cost=0,done=0;
        for(int i=0;i<c;i++)
        {
            int r1=getRoot(sub[data[i].u]);
            int r2=getRoot(sub[data[i].v]);
            int money=data[i].c;
            
            if(r1!=r2)
            {
                unionset(r1,r2);
                done++;
                cost+=money;
            }
            
            if(done==(c-1))
                break;
        }
        
        int root=getRoot(sub[start]);
        bool impos=false;
        for(int i=1;i<=s;i++)
            if(getRoot(sub[place[i]])!=root)
            {
                impos=true;
                break;
            }

        if(!impos)
            printf("%d\n",cost);
        else printf("Impossible\n");
    }
    return 0;
}
