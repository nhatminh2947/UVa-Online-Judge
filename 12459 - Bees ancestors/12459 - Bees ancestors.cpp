//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 12459 - Bees ancestors
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

long long F[100];

void solve()
{
	fill(F,F+90,0);
	F[1] = 1;
	F[2] = 2;
	
	for(int i = 3 ; i <= 80 ; i++)
		F[i] = F[i-2] + F[i-1];
	
}

int main()
{
	freopen("12459 - Bees ancestors.INP","r",stdin);
	freopen("12459 - Bees ancestors.OUT","w",stdout);
	int n;
	solve();
	while(scanf(" %d ",&n) && n)
	{
		printf("%lld\n",F[n]);
	}
	return 0;
}

