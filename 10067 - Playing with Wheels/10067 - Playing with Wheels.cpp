//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10067 - Playing with Wheels
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

struct stt
{
	int a,b,c,d;
	stt()
	{
		a = b = c = d = 0;
	}
};

int step[15][15][15][15];
stt st,ed;

void init()
{
	for(int i = 0 ; i <= 9; i++)
		for(int j = 0 ; j <= 9 ; j++)
			for(int k = 0 ; k <= 9 ; k++)
				for(int l = 0 ; l <= 9 ; l++)
					step[i][j][k][l] = INF;
}

int BFS()
{	
	queue<stt> q;
	q.push(st);
	step[st.a][st.b][st.c][st.d] = 0;
	
	while(!q.empty())
	{
		stt t = q.front();
		
		if(t.a == ed.a && t.b == ed.b && t.c == ed.c && t.d == ed.d)
			return step[ed.a][ed.b][ed.c][ed.d];
		
		q.pop();
		
		int aa = (t.a+1)%10;
		int bb = (t.b+1)%10;
		int cc = (t.c+1)%10;
		int dd = (t.d+1)%10;
		if(step[aa][t.b][t.c][t.d] != -1 && step[aa][t.b][t.c][t.d] == INF)
		{
			stt k = t;
			k.a = aa;
			step[aa][t.b][t.c][t.d] = step[t.a][t.b][t.c][t.d] + 1;
			q.push(k);
		}
		if(step[t.a][bb][t.c][t.d] != -1 && step[t.a][bb][t.c][t.d] == INF)
		{
			stt k = t;
			k.b = bb;
			step[t.a][bb][t.c][t.d] = step[t.a][t.b][t.c][t.d] + 1;
			q.push(k);
		}
		if(step[t.a][t.b][cc][t.d] != -1 && step[t.a][t.b][cc][t.d] == INF)
		{
			stt k = t;
			k.c = cc;
			step[t.a][t.b][cc][t.d] = step[t.a][t.b][t.c][t.d] + 1;
			q.push(k);
		}
		if(step[t.a][t.b][t.c][dd] != -1 && step[t.a][t.b][t.c][dd] == INF)
		{
			stt k = t;
			k.d = dd;
			step[t.a][t.b][t.c][dd] = step[t.a][t.b][t.c][t.d] + 1;
			q.push(k);
		}
		
		aa = (t.a+9)%10;
		bb = (t.b+9)%10;
		cc = (t.c+9)%10;
		dd = (t.d+9)%10;
		if(step[aa][t.b][t.c][t.d] != -1 && step[aa][t.b][t.c][t.d] == INF)
		{
			stt k = t;
			k.a = aa;
			step[aa][t.b][t.c][t.d] = step[t.a][t.b][t.c][t.d] + 1;
			q.push(k);
		}
		if(step[t.a][bb][t.c][t.d] != -1 && step[t.a][bb][t.c][t.d] == INF)
		{
			stt k = t;
			k.b = bb;
			step[t.a][bb][t.c][t.d] = step[t.a][t.b][t.c][t.d] + 1;
			q.push(k);
		}
		if(step[t.a][t.b][cc][t.d] != -1 && step[t.a][t.b][cc][t.d] == INF)
		{
			stt k = t;
			k.c = cc;
			step[t.a][t.b][cc][t.d] = step[t.a][t.b][t.c][t.d] + 1;
			q.push(k);
		}
		if(step[t.a][t.b][t.c][dd] != -1 && step[t.a][t.b][t.c][dd] == INF)
		{
			stt k = t;
			k.d = dd;
			step[t.a][t.b][t.c][dd] = step[t.a][t.b][t.c][t.d] + 1;
			q.push(k);
		}
		
	}
	
	return -1;
}

int main()
{
	freopen("10067 - Playing with Wheels.INP","r",stdin);
	freopen("10067 - Playing with Wheels.OUT","w",stdout);
	int tcs;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		scanf(" %d %d %d %d ",&st.a,&st.b,&st.c,&st.d);
		scanf(" %d %d %d %d ",&ed.a,&ed.b,&ed.c,&ed.d);
		init();
		int m;
		scanf(" %d ",&m);
		for(int i = 0 ; i < m ; i++)
		{
			int a,b,c,d;
			scanf(" %d %d %d %d ",&a,&b,&c,&d);
			step[a][b][c][d] = -1;
		}
		
		int ans = BFS();
		printf("%d\n",ans);
	}
	return 0;
}

