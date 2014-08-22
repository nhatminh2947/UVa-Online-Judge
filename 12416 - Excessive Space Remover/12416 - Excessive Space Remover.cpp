//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 12416 - Excessive Space Remover
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
	freopen("12416 - Excessive Space Remover.INP","r",stdin);
	freopen("12416 - Excessive Space Remover.OUT","w",stdout);
	string s;
	while(getline(cin,s))
	{
		int cnt = -INF;
		int sz = s.size();
		int k = 0;
		for(int i = 0 ; i < sz ; i++)
		{
			if(s[i] == ' ')
				k++;
			else
			{
				cnt = max(cnt,k);
				k = 0;
			}
		}
		
		cnt = max(cnt,k);
		int ans = 0;
		for(int i = 1 ; i < cnt ; i*=2)
			ans++;
		
		printf("%d\n",ans);
	}
	return 0;
}

