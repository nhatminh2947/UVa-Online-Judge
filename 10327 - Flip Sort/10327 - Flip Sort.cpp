//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10327 - Flip Sort
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

int a[10000005];
int pos[10000005];

int main()
{
	freopen("10327 - Flip Sort.INP","r",stdin);
	freopen("10327 - Flip Sort.OUT","w",stdout);
	int n;
	while(scanf(" %d ",&n) == 1)
	{
		for(int i = 1 ; i <= n ; i++)
			scanf(" %d ",&a[i]);
		
		int cnt = 0;
		for(int i = 2 ; i <= n ; i++)
		{
			int j = i;
			while((j-1) && a[j-1] > a[j])
			{
				swap(a[j-1],a[j]);
				cnt++;
				j--;
			}
		}
			
		printf("Minimum exchange operations : %d\n",cnt);
	}
	return 0;
}

