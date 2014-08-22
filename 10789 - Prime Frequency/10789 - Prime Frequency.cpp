//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10789 - Prime Frequency
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

using namespace std;

char inp[2005];
bool check[2050];

void sieve()
{
	for(int i = 0 ; i <= 2001 ; i++)
		check[i] = true;
	check[0] = check[1] = false;
	
	for(int i = 2 ; i <= 2001 ; i++)
		if(check[i])
		{
			for(int j = i ; i*j <= 2001 ; j++)
				check[i*j] = false;
		}
}

int main()
{
	freopen("10789 - Prime Frequency.INP","r",stdin);
	freopen("10789 - Prime Frequency.OUT","w",stdout);
	int tcs;
	sieve();
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		scanf(" %s ",&inp);
		int sz = strlen(inp);
		int cnt = 1;
		sort(inp,inp+sz);
		printf("Case %d: ",t);
		bool ans = false;
		for(int i = 1 ; i <= sz ; i++)
		{
			if(inp[i] != inp[i-1] || i == sz)
			{
				if(check[cnt])
				{
					printf("%c",inp[i-1]);
					ans = true;
				}
				cnt = 1;
			}
			else cnt++;
		}
		if(!ans)
			printf("empty");
		printf("\n");
	}
	return 0;
}

