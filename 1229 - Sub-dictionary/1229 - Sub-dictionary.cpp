//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1229 - Sub-dictionary
// Verdict: Wrong Answer
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

vector< vector<string> > ans;
vector<int> adj[105];
map<string,int> m;
stack<int> s;
string str[105];
int low[105],ind[105];
bool onStack[105];
int n,id;

inline void init()
{
    id = 0;
    m.clear();
    ans.clear();
    while(!s.empty())
        s.pop();
    for(int i = 1 ; i <= n ; i++)
    {
        low[i] = ind[i] = INF;
        onStack[i] = false;
        adj[i].clear();
    }
}

inline int Tarjan(int u)
{
    low[u] = ind[u] = id++;
    onStack[u] = true;
    s.push(u);
    int v;
    int sz = adj[u].size();
    
    for(int i = 0 ; i < sz ; i++)
    {
        v = adj[u][i];
        if(ind[v] == INF)
        {
            Tarjan(v);
            low[u] = min(low[v],low[u]);
        }
        else if(onStack[v])
            low[u] = min(low[u],ind[v]);
    }
    
    if(low[u] == ind[u])
    {
        vector<string> vi;
        printf("SCC:");
        do
        {
            v = s.top();
            s.pop();
            onStack[v] = false;
            vi.pb(str[v]);
            cout << " " << str[v];
        }while(u != v);
        printf("\n");
        DEBUG(vi.size());
        if(vi.size() != 1)
            ans.pb(vi);
    }
}

bool cmp(vector<string> a, vector<string> b)
{
    return a.size() < b.size();
}

int main()
{
	freopen("1229 - Sub-dictionary.INP","r",stdin);
	freopen("1229 - Sub-dictionary.OUT","w",stdout);
	
	while(scanf(" %d ",&n) && n)
	{
	    init();
	    int cnt = 0;
	    for(int i = 0 ; i < n ; i++)
	    {
	        char s[1000];
	        gets(s);
	        int sz = strlen(s);
	        s[sz] = ' ';
	        sz++;
	        s[sz] = '\0';
	        string u,v;
	        int i = 0;
	        for(i ; i < sz ; i++)
                if(s[i] == ' ')
                {
                    i++;
                    break;
                }
                else u += s[i];
            if(!m[u])
            {
                m[u] = ++cnt;
                str[cnt] = u;
            }
            //cout << u << " ";
            int mu = m[u];
	        u.clear();
	        v.clear();
            for(i ; i < sz ; i++)
                if(s[i] == ' ' && v.size())
                {
                    if(!m[v])
                    {
                        m[v] = ++cnt;
                        str[cnt] = v;
                    }
                    //cout << v << " ";
                    adj[mu].pb(m[v]);
                    v.clear();
                }
                else v += s[i];
            //printf("\n");
	    }
	    
	    for(int i = 1 ; i <= n ; i++)
            if(ind[i] == INF)
                Tarjan(i);
        
        sort(ans.begin(),ans.end(),cmp);
        sort(ans[0].begin(),ans[0].end());
        int sz = ans[0].size();
        printf("%d\n",sz);
        cout << ans[0][0];
        for(int i = 1 ; i < sz ; i++)
            cout << " " << ans[0][i];
        printf("\n");
	}

	return 0;
}

