//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 12247 - Jollo
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
	freopen("12247 - Jollo.INP","r",stdin);
	freopen("12247 - Jollo.OUT","w",stdout);
	int a[5];
	int b[5];
	int c[5];
	bool check[60];
	while(scanf(" %d %d %d %d %d ",&a[0],&a[1],&a[2],&b[0],&b[1]) && a[0])
	{
		sort(a,a+3);
		int ans = -1;
		fill(check,check+55,false);
		check[a[0]] = check[a[1]] = check[a[2]] = check[b[0]] = check[b[1]] = true;
		
		for(int i = 1 ; i <= 52 && ans == -1 ; i++)
		{
			if(check[i])
				continue;
			else
			{
				c[0] = b[0];
				c[1] = b[1];
				c[2] = i;
				sort(c,c+3);
				if(c[0] < a[1] && c[1] < a[2])
					continue;
				else ans = i;
			}
		}
		
		printf("%d\n",ans);
	}
	return 0;
}

