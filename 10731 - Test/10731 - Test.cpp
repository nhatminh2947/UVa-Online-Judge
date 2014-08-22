//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10731 - Test
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
#define maxN 1000
#define INF 1000111222

using namespace std;

vector<int> adj[maxN];
vector< vector<int> > ans;
stack<int> s;
int n,id;
int low[maxN],ind[maxN];
bool onStack[maxN],ap[maxN];

void init()
{
    id = 0;
    ans.clear();
    for(int i = 'A' ; i <= 'Z' ; i++)
    {
        low[i] = ind[i] = INF;
        onStack[i] = ap[i] = false;
        adj[i].clear();
    }
    while(!s.empty())
        s.pop();
}

inline void Tarjan(int u)
{
    low[u] = ind[u] = id++;
    s.push(u);
    onStack[u] = true;
    int v;
    int sz = adj[u].size();
    for(int i = 0 ; i < sz ; i++)
    {
        v = adj[u][i];
        if(ind[v] == INF)
        {
            Tarjan(v);
            low[u] = min(low[u],low[v]);
        }
        else if(onStack[v])
            low[u] = min(low[u],ind[v]);
    }
    
    if(low[u] == ind[u])
    {
        vector<int> tmp;
        do
        {
            v = s.top();
            s.pop();
            onStack[v] = false;
            tmp.pb(v);
        }while(u != v);
        
        sort(tmp.begin(),tmp.end());
        ans.pb(tmp);
    }
}

int main()
{
	freopen("10731 - Test.INP","r",stdin);
	freopen("10731 - Test.OUT","w",stdout);
	bool enter = false;
	while(scanf(" %d ",&n) && n)
	{
	    if(enter)
            printf("\n");
        else enter = true;
        init();
        for(int i = 0 ; i < n ; i++)
        {
            char a[5],k;
            scanf(" %c %c %c %c %c %c ",&a[0],&a[1],&a[2],&a[3],&a[4],&k);
            for(int i = 0 ; i < 5 ; i++)
            {
                ap[a[i]] = true;
                if(k != a[i])
                    adj[k].pb(a[i]);
            }
        }
        
        for(int i = 'A' ; i <= 'Z' ; i++)
            if(ap[i] && ind[i] == INF)
                Tarjan(i);
        
        sort(ans.begin(),ans.end());
        
        int sz = ans.size();
        for(int i = 0 ; i < sz ; i++)
        {
            int szz = ans[i].size();
            printf("%c",ans[i][0]);
            for(int j = 1 ; j < szz ; j++)
                printf(" %c",ans[i][j]);
            printf("\n");
        }
	}

	return 0;
}

