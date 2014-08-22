//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 12157 - Tariff Plan
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

long long a[25];

long long mile(long long n)
{
	long long res = 0;
	int k = n / 30;
	for(int i = 0 ; i <= k ; i++)
		res += 10;
	return res;
}

long long juice(long long n)
{
	long long res = 0;
	int k = n / 60;
	for(int i = 0 ; i <= k ; i++)
		res += 15;
	return res;
}

int main()
{
	freopen("12157 - Tariff Plan.INP","r",stdin);
	freopen("12157 - Tariff Plan.OUT","w",stdout);
	int tcs,n;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		scanf(" %d ",&n);
		for(int i = 0 ; i < n ; i++)
			scanf(" %lld ",&a[i]);
		
		long long m = 0;
		long long j = 0;
		
		for(int i = 0 ; i < n ; i++)
		{
			m += mile(a[i]);
			j += juice(a[i]);
		}
		printf("Case %d: ",t);
		if(m < j)
			printf("Mile %lld\n",m);
		else if(j < m)
			printf("Juice %lld\n",j);
		else printf("Mile Juice %lld\n",m);
	}
	return 0;
}

