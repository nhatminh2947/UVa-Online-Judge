//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 
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
	int x,y;
}point;

int n,a,b;
point p[105];
vector< pair<int,double> > data[105];

double dist(point a, point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

void dij()
{
	set< pair<int,double> > s;
	
	s.insert(mp(0,0));
	
	while(!q.empty())
	{
		
	}
}

int main()
{
	freopen("1096.INP","r",stdin);
	freopen("1096.OUT","w",stdout);
	while(scanf(" %d %d %d ",&n,&a,&b) && n)
	{
		for(int i = 0 ; i < n ; i++)
		{
			scanf(" %d %d ",&p[i].x,&p[i].y);
			data[i].clear();
		}
		
		for(int i = 0 ; i < n-1 ; i++)
			for(int j = i+1 ; j < n ; j++)
			{
				double d = dist(p[i],p[j]);
				data[i].pb(mp(j,d));
				data[j].pb(mp(i,d));
			}
		
		
	}
	return 0;
}

