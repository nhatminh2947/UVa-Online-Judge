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

struct point
{
	int a,b;
	
	point()
	{
		a = b = 0;
	}
};

double len_edge(point a, point b)
{
	return sqrt((a.a-b.a)*(a.a-b.a) + (a.b-b.b)*(a.b-b.b));
}

double area(point a, point b, point c)
{
	double l1 = len_edge(a,b);
	double l2 = len_edge(b,c);
	double l3 = len_edge(c,a);
		
	double p = (l1+l2+l3)/2;
		
	return sqrt(p*(p-l1)*(p-l2)*(p-l3));
}

point p[1005];

int main()
{
	freopen("12426.INP","r",stdin);
	freopen("12426.OUT","w",stdout);
	int tcs,n,m;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		scanf(" %d %d ",&n, &m);
		for(int i = 0 ; i < n ; i++)
			scanf(" %d %d ",&p[i].a, &p[i].b);
		
		int64 cnt = 0;
		for(int i = 0 ; i < n-2 ; i++)
			for(int j = i+1 ; j < n-1 ; j++)
				for(int k = j+1 ;  k < n ; k++)
					if(area(p[i],p[j],p[k]) <= m)
						cnt++;
		
		printf("%lld\n",cnt);
	}
	return 0;
}

