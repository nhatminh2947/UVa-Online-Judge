//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 12239 - Bingo!
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

int main()
{
	freopen("12239 - Bingo!.INP","r",stdin);
	freopen("12239 - Bingo!.OUT","w",stdout);
	int n,b;
	int a[100];
	bool check[100];
	while(scanf(" %d %d ",&n,&b) && n)
	{
		for(int i = 0 ; i <= n ; i++)
			check[i] = false;
		
		for(int i = 0 ; i < b ; i++)
			scanf(" %d ",&a[i]);
		
		for(int i = 0 ; i < b ; i++)
			for(int j = 0 ; j < b ; j++)
				check[abs(a[i]-a[j])] = true;
			
		bool ans = true;
		for(int i = 0 ; i <= n ; i++)
			if(check[i] == false)
			{
				ans = false;
				break;
			}
		
		if(ans)
			puts("Y");
		else puts("N");
	}
	return 0;
}

