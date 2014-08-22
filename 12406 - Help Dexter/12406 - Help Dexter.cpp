//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 12406 - Help Dexter
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

int p,q;
bool ans;
int64 mi,ma;

void solve(int64 n, len)
{
	if(len == p)
	{
		if(n % q)
		{
			
		}
		return;
	}
}

int main()
{
	freopen("12406 - Help Dexter.INP","r",stdin);
	freopen("12406 - Help Dexter.OUT","w",stdout);
	int tcs;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		scanf(" %lld %lld ",&p,&q);
		q = (1 << q);
		ans = false;
		solve(0,0);
		printf("Case %d:",t);
	}
	return 0;
}

