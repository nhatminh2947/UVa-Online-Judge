//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 12114 - Bachelor Arithmetic
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

int main()
{
	freopen("12114 - Bachelor Arithmetic.INP","r",stdin);
	freopen("12114 - Bachelor Arithmetic.OUT","w",stdout);
	int s,b;
	int tcs = 1;
	while(scanf(" %d %d ",&b,&s) && b)
	{
		printf("Case %d: ",tcs++);
		if(b == 0 || b == 1)
			puts(":-\\");
		else if(s >= b)
			puts(":-|");
		else puts(":-(");
	}
	return 0;
}

