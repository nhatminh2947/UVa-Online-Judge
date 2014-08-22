//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10139 - Factovisors
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

vector<int64> primes;
bool check[50005];

void sieve()
{
	for(int64 i = 0 ; i < 46500 ; i++)
		check[i] = true;
		
	for(int64 i = 2 ; i < 46500 ; i++)
		if(check[i])
		{
			primes.pb(i);
			for(int64 j = i ; i*j < 46500 ; j++)
				check[i*j] = false;
		}
}

int64 get_powers(int64 n, int64 p)
{
	int64 res = 0;
	for(int64 powers = p ; powers <= n ; powers *= p)
		res += n/powers;
	return res;
}

int main()
{
	freopen("10139 - Factovisors.INP","r",stdin);
	freopen("10139 - Factovisors.OUT","w",stdout);
	int64 a,b;
	
	sieve();
	while(scanf(" %lld %lld ",&a,&b) == 2)
	{
		bool ans = true;
		int64 tmp = b;
		if(b == 0)
			ans = false;
		
		if(ans && a < b && b != 1)
		{
			int p = 0;
			int sz = primes.size();
			while(a < b && ans && p < sz && primes[p] <= (int)sqrt(b))
			{
				int64 d,powers;
				if(b % primes[p] == 0)
				{
					for(int64 i = primes[p], c = 1 ; i <= b ; i *= primes[p], c++)
						if(b % i == 0)
						{
							powers = c;
							d = i;
						}
					b /= d;
					if(powers > get_powers(a,primes[p]))
						ans = false;
				}
				p++;
			}
		}
		
		if(!ans || (b > a && b != 1))
			printf("%lld does not divide %lld!\n",tmp,a);
		else printf("%lld divides %d!\n",tmp,a);
	}
	return 0;
}

