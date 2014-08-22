//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10557 - XYZZY
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

struct edge
{
	int u,v,w;
	edge() {}
};

edge e[100005];
int dist[105];
int n;

bool Bellman_Ford(int cntE)
{
	fill(dist+1,dist+n+1,INF);
	dist[1] = 100;
	
	for(int i = 1 ; i <= n ; i++)
		for(int j = 0 ; j < cntE ; j++)
		{
			if(dist[e[j].u] != INF)
			{
				if(dist[e[j].u] + e[j].w < dist[e[j].v])
					dist[e[j].v] = dist[e[j].u] + e[j].w;
			}
		}
	
	for(int i = 0 ; i < cntE ; i++)
		if(dist[e[i].u] + e[i].w < dist[e[i].v])
			return true;
	if(dist[n] > 0)
		return true;
	return false;
}

int main()
{
	freopen("10557 - XYZZY.INP","r",stdin);
	freopen("10557 - XYZZY.OUT","w",stdout);
	while(scanf(" %d ",&n) && n != -1)
	{
		int cnt = 0;
		for(int i = 1 ; i <= n ; i++)
		{
			int ene,k;
			scanf(" %d %d ",&ene,&k);
			for(int j = 1 ; j <= k ; j++)
			{
				int tmp;
				scanf(" %d ",&tmp);
				e[cnt].u = i;
				e[cnt].v = tmp;
				e[cnt].w = -ene;
				cnt++;
			}
		}
		
		if(Bellman_Ford(cnt))
			puts("winnable");
		else puts("hopeless");
		
	}
	return 0;
}

