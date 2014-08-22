//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10807 - Prim
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
	int u,v,w;
}edge;

edge e[30],tmp[30];
bool check[30];
int lab[15];
int n,m;

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

bool cmp(edge a, edge b)
{
	return a.w < b.w;
}

int Kruskal()
{
	for(int i = 1 ; i <= n ; i++)
		lab[i] = i;
	
	int done = 0;
	int cost = 0;
	for(int i = 0 ; i < m ; i++)
	{
		if(check[i]) continue;
		int u = getRoot(e[i].u);
		int v = getRoot(e[i].v);
		int w = e[i].w;
		
		if(u != v)
		{
			check[i] = true;
			cost += w;
			done++;
			unionset(u,v);
		}
		
		if(done == (n-1))
			return cost;
	}
	
	return INF;
}

void reset()
{
	for(int i = 0 ; i < m ; i++)
		check[i] = false;
}

int main()
{
	freopen("10807 - Prim.INP","r",stdin);
	freopen("10807 - Prim.OUT","w",stdout);
	while(scanf(" %d ",&n) && n)
	{
		scanf(" %d ",&m);
		for(int i = 0 ; i < m ; i++)
			scanf(" %d %d %d ",&e[i].u,&e[i].v,&e[i].w);
		for(int i = 0 ; i < m ; i++)
			tmp[i] = e[i];
		
		sort(e,e+m,cmp);
		int ans = INF;
		do
		{
			int a = Kruskal();
			ans = min(ans,a + Kruskal());
			reset();
		}while(next_permutation(e,e+m,cmp));
		
		if(ans == INF)
			puts("No way!");
		else printf("%d\n",ans);
	}
	return 0;
}

