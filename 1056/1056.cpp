//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1056 - 
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
#include <cctype>
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define maxN 123456
#define INF 1000111222

using namespace std;

typedef struct
{
	int u,v;
}edge;

map<string,int> enc;
edge rel[100005];
int lab[100005];
vector<int> data[100005];
int dist[100005];
int p,r;

int getRoot(int u)
{
	if(lab[u] == u)
		return u;
	return lab[u] = getRoot(lab[u]);
}

int unionset(int u,int v)
{
	return lab[u] = v;
}

int BFS()
{
	fill(dist,dist+r+3,INF);
	
	queue<int> q;
	q.push(1);
	dist[1] = 0;
	int m = -INF;
	while(!q.empty())
	{
		int tmp = q.front();
		m = max(m,dist[tmp]);
		q.pop();
		
		int sz = data[tmp].size();
		
		for(int i = 0 ; i < sz ; i++)
		{
			if(dist[data[tmp][i]] == INF)
			{
				dist[data[tmp][i]] = dist[tmp] + 1;
				q.push(data[tmp][i]);
			}
		}
	}
	return m;
}

int main()
{
	freopen("1056.INP","r",stdin);
	freopen("1056.OUT","w",stdout);
	int tcs = 1;
	while(scanf(" %d %d ",&p,&r) && p)
	{
		enc.clear();
		int cnt = 1;
		for(int i = 0 ; i < r ; i++)
		{
			string u,v;
			cin >> u >> v;
			
			if(!enc[u])
				enc[u] = cnt++;
			if(!enc[v])
				enc[v] = cnt++;
			
			rel[i].u = enc[u];
			rel[i].v = enc[v];
		}
		
		for(int i = 1 ; i <= p ; i++)
			lab[i] = i;
		int done = 0;
		for(int i = 0 ; i < r ; i++)
		{
			int u = getRoot(rel[i].u);
			int v = getRoot(rel[i].v);
			
			if(u != v)
			{
				unionset(u,v);
				done++;
				data[u].pb(v);
				data[v].pb(u);
			}
		}
		
		set<int> s;
		for(int i = 1 ; i <= p ; i++)
			s.insert(getRoot(i));
		printf("Network %d: ",tcs++);
		if(s.size() != 1)
			puts("DISCONNECTED");
		else
		{
			int ans = BFS();
			printf("%d\n",ans);
		}
		printf("\n");
	}
	return 0;
}

