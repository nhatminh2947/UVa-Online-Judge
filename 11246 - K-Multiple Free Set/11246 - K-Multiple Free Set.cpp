//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 11246 - K-Multiple Free Set
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


int main()
{
	freopen("11246 - K-Multiple Free Set.INP","r",stdin);
	freopen("11246 - K-Multiple Free Set.OUT","w",stdout);
	int tcs;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		queue<int> q;
		int n,k;
		scanf(" %d %d ",&n,&k);
		
		int cnt = 0;
		for(int i = 1 ; i*k <= n ; i++)
			if(i % k != 0)
				cnt++;
			else if((i % k == 0) && q.front() == i)
			{
				cnt++;
				q.pop();
			}
			else q.push(i*k);
		
		printf("%d\n",n - cnt);
		
	}
	return 0;
}

