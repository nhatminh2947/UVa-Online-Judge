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
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define maxN 2000000
#define INF 1000111222
#define int64 long long

using namespace std;

vector<int> primes;
int X[100005];
bool check[maxN + 5];
int tcs,n,m;

void sieve()
{
	for(int64 i = 0 ; i < maxN ; i++)
		check[i] = true;
		
	for(int64 i = 2 ; i < maxN ; i++)
	{
		if(check[i])
		{
			for(int64 j = i ; i*j < maxN ; j++)
				check[i*j] = false;
			primes.pb(i);
		}
	}
}

int main()
{
	freopen("12384.INP","r",stdin);
	freopen("12384.OUT","w",stdout);
	sieve();
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		scanf(" %d %d ",&n,&m);
		int sz = primes.size();
		for(int i = 0 ; i < n ; i++)
		{
			X[i] = primes[i] % m;
			printf("%d ",X[i]);
		}
		printf("\n");
	}
	return 0;
}

