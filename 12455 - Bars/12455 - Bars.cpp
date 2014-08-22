//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 12455 - Bars
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

int a[25];
bool ans;
int tcs,n,len;

void solve(int k, int sum)
{
	if(sum == len)
		ans = true;
	if(k >= n)
		return;
	if(ans)
		return;
	
	int tmp = sum + a[k];
	solve(k+1,tmp);
	solve(k+1,sum);
}

int main()
{
	freopen("12455 - Bars.INP","r",stdin);
	freopen("12455 - Bars.OUT","w",stdout);
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		scanf(" %d ",&len);
		scanf(" %d ",&n);
		for(int i = 0 ; i < n ; i++)
			scanf(" %d ",&a[i]);
		ans = false;
		solve(0, 0);
		if(ans)
			puts("YES");
		else puts("NO");
	}
	return 0;
}

