//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 12136 - Schedule of a Married Man
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

pair< pair<int,int>, pair<int,int> > a[5];

int main()
{
	freopen("12136 - Schedule of a Married Man.INP","r",stdin);
	freopen("12136 - Schedule of a Married Man.OUT","w",stdout);
	int tcs;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		char s1[10], s2[10], s3[10], s4[10];
		scanf(" %s %s %s %s ",&s1, &s2, &s3, &s4);
		
		sscanf(s1,"%d:%d",&a[1].ff.ff,&a[1].ff.ss);
		sscanf(s2,"%d:%d",&a[1].ss.ff,&a[1].ss.ss);
		
		sscanf(s3,"%d:%d",&a[2].ff.ff,&a[2].ff.ss);
		sscanf(s4,"%d:%d",&a[2].ss.ff,&a[2].ss.ss);
		printf("Case %d: ",t);
		if((a[2].ss.ff < a[1].ff.ff) || ((a[2].ss.ff == a[1].ff.ff) && (a[2].ss.ss < a[1].ff.ss)))
			puts("Hits Meeting");
		else if((a[1].ss.ff < a[2].ff.ff) || ((a[1].ss.ff == a[2].ff.ff) && (a[1].ss.ss < a[2].ff.ss)))
			puts("Hits Meeting");
		else puts("Mrs Meeting");
	}
	return 0;
}

