//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 11060 - Beverages
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
#define int64 long long
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

map<string,int> c;
vector<int> in[300];
queue<int> out[300];
string str[300];
bool vis[300];
int n,m,lim;

int main()
{
	freopen("11060 - Beverages.INP","r",stdin);
	freopen("11060 - Beverages.OUT","w",stdout);
	int tcs = 1;
	while(scanf(" %d ",&n) == 1)
	{
	    printf("Case #%d: Dilbert should drink beverages in this order:",tcs++);
	    c.clear();
	    for(int i = 1 ; i <= n ; i++)
	    {
	        in[i].clear();
	        vis[i] = false;
	        cin >> str[i];
	        c[str[i]] = i;
	    }
	    scanf(" %d ",&m);
	    for(int i = 0 ; i < m ; i++)
	    {
	        string s1,s2;
	        cin >> s1 >> s2;
	        int cs1 = c[s1];
	        int cs2 = c[s2];
	        
	        out[cs1].push(cs2);
	        in[cs2].pb(cs1);
	    }
	    
	    for(int i = 1 ; i <= n ; i++)
	    {
	        if(in[i].empty() && !vis[i])
	        {
	            cout << " " << str[i];
	            vis[i] = true;
	            while(!out[i].empty())
	            {
	                int v = out[i].front();
	                out[i].pop();
	                vector<int>::iterator it;
	                it = find(in[v].begin(),in[v].end(),i);
	                if(it != in[v].end())
                        in[v].erase(it);
	            }
	            i = 0;
	        }
	    }
	    
	    printf(".\n\n");
	}

	return 0;
}

