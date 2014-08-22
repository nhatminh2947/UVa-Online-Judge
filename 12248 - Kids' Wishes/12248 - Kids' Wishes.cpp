//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 12248 - Kids' Wishes
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
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define maxN 100000
#define INF 1000111222

using namespace std;

struct edge
{
	int u,v;
};

map<int,int> m;
set< pair<int,int> > s;
edge e[maxN+5];
int lab[maxN+5];
int con[maxN+5];
int k,w;

int getRoot(int u)
{
	if(lab[u] == u)
		return u;
	return lab[u] = getRoot(lab[u]);
}

int unionset(int u, int v)
{
	return lab[u] = v;
}

int main()
{
	freopen("12248 - Kids' Wishes.INP","r",stdin);
	freopen("12248 - Kids' Wishes.OUT","w",stdout);
	while(scanf(" %d %d ",&k,&w) && k)
	{
		m.clear();
		s.clear();
		int n = 1;
		int W = 0;
		bool ans = true;
		for(int i = 0 ; i <= maxN ; i++)
			con[i] = 0;
		
		for(int i = 0 ; i < w ; i++)
		{
			int u,v;
			scanf(" %d %d ",&u,&v);
			
			if(!m[u])
				m[u] = n++;
			if(!m[v])
				m[v] = n++;
			
			if(s.find(mp(u,v)) != s.end())
				continue;
			
			int mu = m[u];
			int mv = m[v];
			
			con[mu]++;
			con[mv]++;
			if(con[mu] > 2 || con[mv] > 2)
				ans = false;
			
			e[W].u = u;
			e[W].v = v;
			W++;
			s.insert(mp(u,v));
			s.insert(mp(v,u));
		}
		
		if(!ans)
		{
			puts("N");
			continue;
		}
		
		for(int i = 1 ; i < n ; i++)
			lab[i] = i;
		
		int cnt = 0;
		for(int i = 0 ; i < W ; i++)
		{
			int eu = m[e[i].u];
			int ev = m[e[i].v];
			
			int u = getRoot(lab[eu]);
			int v = getRoot(lab[ev]);
			
			if(u != v)
			{
				unionset(u,v);
				cnt++;
			}
		}
		
		if(cnt == W)
			puts("Y");
		else
		{
			if(cnt == (W-1))
			{
				bool b = true;
				for(int i = 1 ; i < n && b ; i++)
					if(con[i] != 2)
						b = false;
				
				if(b && (n-1)==k)
					puts("Y");
				else puts("N");
			}
			else puts("N");
		}
	}
	return 0;
}

