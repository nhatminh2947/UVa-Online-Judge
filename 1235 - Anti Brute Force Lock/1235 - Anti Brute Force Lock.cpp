//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1235 - Anti Brute Force Lock
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

typedef struct edge
{
    int u,v,w;
};

string data[5005];
edge e[250005];
int lab[250005];

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

int getRoot(int u)
{
    if(lab[u] == u)
        return u;
    return lab[u] = getRoot(lab[u]);
}

int unionset(int a,int b)
{
    return lab[a] = b;
}

int main()
{
    freopen("1235 - Anti Brute Force Lock.INP","r",stdin);
    freopen("1235 - Anti Brute Force Lock.OUT","w",stdout);
    int tcs,n;
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        scanf(" %d ",&n);
        for(int i = 0 ; i < n ; i++)
            cin >> data[i];
        data[n] = "0000";
        int cnt = 0;
        for(int i = 0 ; i < n-1 ; i++)
            for(int j = i+1 ; j < n ; j++)
            {
                e[cnt].u = i;
                e[cnt].v = j;
                int sum = 0;
                for(int k = 0 ; k < 4 ; k++)
                    sum += min((data[i][k]-data[j][k] + 10)%10,(data[j][k]-data[i][k] + 10)%10);
                e[cnt].w = sum;
                cnt++;
            }
        
        sort(e,e+cnt,cmp);
        for(int i = 0 ; i <= n ; i++)
            lab[i] = i;
        
        int done = 0;
        int cost = 0;
        for(int i = 0 ; i < cnt ; i++)
        {
            int u = getRoot(e[i].u);
            int v = getRoot(e[i].v);
            int w = e[i].w;
            
            if(u != v)
            {
                unionset(u,v);
                done++;
                cost += w;
            }
            
            if(done == n-1)
                break;
        }
        
        int m = INF;
        
        for(int i = 0 ; i < n ; i++)
        {
            int sum = 0;
            for(int j = 0 ; j < 4 ; j++)
                sum += min((data[n][j]-data[i][j]+10)%10,(data[i][j]-data[n][j]+10)%10);
            m = min(m,sum);
        }
        
        printf("%d\n",cost+m);
    }
    return 0;
}
