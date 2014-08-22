//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 12149 - Feynman
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

long long F[105];

void pre_cal()
{
	F[0] = 0;
	for(int i = 1 ; i <= 100 ; i++)
		F[i] = F[i-1] + i*i;
}

int main()
{
	freopen("12149 - Feynman.INP","r",stdin);
	freopen("12149 - Feynman.OUT","w",stdout);
	pre_cal();
	int n;
	while(scanf(" %d ",&n) && n)
	{
		printf("%d\n",F[n]);
	}
	return 0;
}

