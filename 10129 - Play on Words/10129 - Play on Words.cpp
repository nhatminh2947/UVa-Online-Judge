//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10129 - Play on Words
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
#define maxN 123456
#define INF 1000111222

using namespace std;

int adj[30][30];
int vis[30][30];
int p[30],in[30],out[30];
bool check[30];
int n,st;

void init()
{
	st = -INF;
	for(int i = 0 ; i < 30 ; i++)
	{
		for(int j = 0 ; j < 30 ; j++)
			adj[i][j] = vis[i][j] = 0;
		in[i] = out[i] = 0;
		p[i] = i;
		check[i] = false;
	}
}

int find_path(int x)
{
	if(p[x] == x)
		return x;
	return p[x] = find_path(p[x]);
}

int main()
{
	freopen("10129 - Play on Words.INP","r",stdin);
	freopen("10129 - Play on Words.OUT","w",stdout);
	int tcs;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		scanf(" %d ",&n);
		init();
		for(int i = 0 ; i < n ; i++)
		{
			char tmp[1005];
			scanf(" %s ",&tmp);
			int u = tmp[0] - 'a';
			int v = tmp[strlen(tmp)-1] - 'a';
			st = max(st,max(u,v));
			adj[u][v]++;
			int uu = find_path(u);
			int vv = find_path(v);
			if(uu != vv)
				p[v] = uu;
			check[u] = check[v] = true;
			in[v]++;
			out[u]++;
		}
		
		bool ans = true;
		for(int i = 0 ; i <= st && ans ; i++)
		{
			if(abs(in[i]-out[i]) > 1)
				ans = false;
			for(int j = 0 ; j <= st && ans ; j++)
				if(check[i] && check[j] && find_path(i) != find_path(j))
					ans = false;
		}
		
		
		
		if(!ans)
			puts("The door cannot be opened.");
		else puts("Ordering is possible.");
	}
	return 0;
}

