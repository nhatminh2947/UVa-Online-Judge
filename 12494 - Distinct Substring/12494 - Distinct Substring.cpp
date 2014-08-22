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
	freopen("12494 - Distinct Substring.INP","r",stdin);
	freopen("12494 - Distinct Substring.OUT","w",stdout);
	int tcs;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		string str;
		cin >> str;
		set<string> s[205],check;
		set<string>::iterator it;
		int sz_str = str.size();
		for(int st = 0 ; st < sz_str ; st++)
		{
			string tmp = "";
			for(int ed = st ; ed < sz_str ; ed++)
			{
				tmp += str[ed];
				int sz_tmp = tmp.size();
				s[sz_tmp].insert(tmp);
			}
		}
		
		int cnt = 0;
		for(int sz = 2 ; sz <= sz_str ; sz++)
		{
			if(s[sz].size() == 1)
			{
				cnt++;
				continue;
			}
			it = s[sz].begin();
			while(it != s[sz].end())
			{
				string a = *it;
				int sz_check = check.size();
				check.insert(a);
				if(sz_check != check.size())
					cnt++;
				
				while(sz_check != check.size())
				{
					sz_check = check.size();
					a = a + a[0];
					a.erase(a.begin());
					check.insert(a);
				}
				
				it++;
			}
			check.clear();
		}

		printf("%d\n",cnt+s[1].size());
	}
	return 0;
}

