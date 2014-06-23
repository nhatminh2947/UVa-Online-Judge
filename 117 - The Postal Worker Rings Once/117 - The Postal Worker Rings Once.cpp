//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 117 - The Postal Worker Rings Once
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
#define i64 long long
#define u64 unsigned long long
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define maxN 123456
#define INF 1000111222

using namespace std;

vector< pair<int,int> > adj[200];
int dist[200];
char str[1000];

int dij(int st, int ed)
{
    set< pair<int,int> > s;
    dist[st] = 0;
    s.insert(mp(0,st));
    
    while(!s.empty())
    {
        pair<int,int> tmp = *s.begin();
        int d = tmp.ff;
        int p = tmp.ss;
        
        if(p == ed)
            return dist[ed];
        
        s.erase(tmp);
        
        int sz = adj[p].size();
        for(int i = 0 ; i < sz ; i++)
        {
            int v = adj[p][i].ff;
            int dis = adj[p][i].ss;
            if(dist[v] > d + dis)
            {
                if(dist[v] != INF)
                    s.erase(mp(dist[v],v));
                dist[v] = d + dis;
                s.insert(mp(dist[v],v));
            }
        }
    }
}

int main()
{
	freopen("117 - The Postal Worker Rings Once.INP","r",stdin);
	freopen("117 - The Postal Worker Rings Once.OUT","w",stdout);
    int sum = 0;
    for(int i = 'a' ; i <= 'z' ; i++)
    {
        adj[i].clear();
        dist[i] = INF;
    }
    while(scanf(" %s ",&str) == 1)
    {
        if(strcmp(str,"deadend") == 0)
        {
            //DEBUG(str);
            int p[3];
            int k = 0;
            for(int i = 'a' ; i <= 'z' && k != 2 ; i++)
                if(adj[i].size() % 2 == 1)
                    p[k++] = i;
                
            //DEBUG(k);
            if(k == 0)
                printf("%d\n",sum);
            else printf("%d\n",dij(p[0],p[1])+sum);
            
            sum = 0;
            for(int i = 'a' ; i <= 'z' ; i++)
            {
                adj[i].clear();
                dist[i] = INF;
            }
        }
        else
        {
            int sz = strlen(str);
            sum += sz;
            adj[str[0]].pb(mp(str[sz-1],sz));
            adj[str[sz-1]].pb(mp(str[0],sz));
        }
    }
	return 0;
}

