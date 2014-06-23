//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 294 - Divisors
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

bool check[40000];
vector<int> primes;

void sieve()
{
	for(int i = 0 ; i < 40000 ; i++)
		check[i] = true;
	
	for(int i = 2 ; i < 40000 ; i++)
	{
		if(check[i])
		{
			for(int64 j = i ; i*j < 40000 ; j++)
				check[i*j] = false;
			primes.pb(i);
		}
	}
}

int main()
{
	freopen("294 - Divisors.INP","r",stdin);
	freopen("294 - Divisors.OUT","w",stdout);
	sieve();
	int tcs;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		int L,U;
		scanf(" %d %d ",&L,&U);
		int sz = primes.size();
		int ans = -INF;
		int n;
		for(int i = L ; i <= U ; i++)
		{
			int res = 1;
			int num = i;
			bool ok = false;
			for(int k = 0 ; primes[k] <= sqrt(num) ; k++)
			{
				if(num % primes[k] == 0)
				{
					int cnt = 0;
					int tmp = primes[k];
					while(num % tmp == 0)
					{
						num /= tmp;
						cnt++;
					}
					res *= (cnt+1);
					ok = true;
				}
			}
			
			if(num != 1)
				res *= 2;
			//cout << num << endl;
			if(ans < res)
			{
				n = i;
				ans = res;
			}
		}
		printf("Between %d and %d, %d has a maximum of %d divisors.\n",L,U,n,ans);
	}
	return 0;
}

