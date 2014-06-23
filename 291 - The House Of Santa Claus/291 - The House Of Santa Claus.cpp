//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 291 - The House Of Santa Claus
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
#define maxN 123456
#define INF 1000111222

using namespace std;

int adj[10][10];

void DFS(int u,vector<int> ans)
{
	if(ans.size() == 9)
	{
		printf("printf(\"");
		for(int i = 0 ; i < ans.size() ; i++)
			printf("%d",ans[i]);
		printf("\\n\")\n");
	}
	for(int v = 1 ; v <= 5 ; v++)
	{
		if(adj[u][v])
		{
			adj[u][v]--;
			adj[v][u]--;
			ans.pb(v);
			DFS(v,ans);
			ans.pop_back();
			adj[u][v]++;
			adj[v][u]++;
		}
	}
}

int main()
{
	freopen("291 - The House Of Santa Claus.INP","r",stdin);
	freopen("291 - The House Of Santa Claus.OUT","w",stdout);
	
	for(int i = 1 ; i <= 5 ; i++)
		for(int j = 1 ; j <= 5 ; j++)
			adj[i][j] = 0;
	
	for(int i = 0 ; i < 8 ; i++)
	{
		int u,v;
		scanf(" %d %d ",&u,&v);
		adj[u][v]++;
		adj[v][u]++;
	}
	vector<int> ans;
	ans.pb(1);
	DFS(1,ans);
	
	return 0;
}

