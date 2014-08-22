//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 12484 - Cards
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
#define int64 long long

using namespace std;

int n;
int64 a[10005];
int64 m;

void solve(int lf, int rg, int k, int64 sum)
{
	if(lf == rg)
	{
		m = max(m,sum);
		return;
	}
	
	if(k == 1)
	{
		solve(lf+1,rg,0,sum+a[lf]);
		solve(lf,rg-1,0,sum+a[rg]);
	}
	else
	{
		solve(lf+1,rg,1,sum);
		solve(lf,rg-1,1,sum);
	}
}

int main()
{
	freopen("12484 - Cards.INP","r",stdin);
	freopen("12484 - Cards.OUT","w",stdout);
	while(scanf(" %d ",&n) == 1)
	{
		for(int i = 0 ; i < n ; i++)
			scanf(" %lld ",&a[i]);
		m = -INF;
		solve(0,n-1,1,0);
		
		printf("%lld\n",m);
	}
	return 0;
}

