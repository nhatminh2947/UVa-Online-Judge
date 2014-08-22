//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 10004 - Bicoloring
//==============================================================

#include <iostream>
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
#define INF 4294967295

using namespace std;

vector<int> data[205];
int C[205];
int n,m;

void init()
{
	for(int i = 0 ; i < n ; i++)
	{
		C[i] = 0;
		data[i].clear();
	}
}

bool BFS()
{
	queue<int> q;
	
	q.push(0);
	C[0] = 1;
	
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		
		int sz = data[u].size();
		for(int i = 0 ; i < sz ; i++)
		{
			int v = data[u][i];
			if(!C[v])
			{
				C[v] = C[u]%2 + 1;
				q.push(v);
			}
			else if(C[v] == C[u])
				return false;
		}
	}
	
	return true;
}

int main()
{
    freopen("10004.INP","r",stdin);
    freopen("10004.OUT","w",stdout);
    while(scanf(" %d ",&n) && n)
    {
		scanf(" %d ",&m);
		init();
		for(int i = 0 ; i < m ; i++)
		{
			int u,v;
			scanf(" %d %d ",&u,&v);
			data[u].push_back(v);
			data[v].push_back(u);
		}
		
		if(BFS())
			puts("BICOLORABLE.");
		else puts("NOT BICOLORABLE.");
		
	}
    return 0;
}
