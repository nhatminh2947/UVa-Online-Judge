//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 12240 - Cocircular Points
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
#define eps 1e-6

using namespace std;

struct point
{
	double x,y;
};

point p[105];
int n;

inline double dist(point a, point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int main()
{
	freopen("12240 - Cocircular Points.INP","r",stdin);
	freopen("12240 - Cocircular Points.OUT","w",stdout);
	while(scanf(" %d ",&n) && n)
	{
		for(int i = 0 ; i < n ; i++)
			scanf(" %lf %lf ",&p[i].x,&p[i].y);
		
		int ans = 2;
		
		for(int i = 0 ; i < n-3 ; i++)
			for(int j = i+1 ; j < n-2 ; j++)
				for(int k = j+1 ; k < n-1 ; k++)
				{
					point C;
					double a1,a2,b1,b2,c1,c2;
	
					a1 = 2*(p[j].x-p[i].x);
					a2 = 2*(p[k].x-p[j].x);
					b1 = 2*(p[j].y-p[i].y);
					b2 = 2*(p[k].y-p[j].y);
					c1 = -(p[i].x)*(p[i].x) + (p[j].x)*(p[j].x) - (p[i].y)*(p[i].y) + (p[j].y)*(p[j].y);
					c2 = -(p[j].x)*(p[j].x) + (p[k].x)*(p[k].x) - (p[j].y)*(p[j].y) + (p[k].y)*(p[k].y);
					
					double D,Dx,Dy;
					
					D = a1*b2-a2*b1;
					if(D == 0)
						continue;
					
					Dx = c1*b2 - c2*b1;
					Dy = a1*c2 - a2*c1;
					
					C.x = Dx/D;
					C.y = Dy/D;
					
					int cnt = 3;
					double d = dist(C,p[k]);
					for(int l = k+1 ; l < n ; l++)
						if(abs(dist(p[l],C) - d) < eps)
							cnt++;
					ans = max(ans,cnt);
				}
		
		printf("%d\n",ans);
	}
	return 0;
}

