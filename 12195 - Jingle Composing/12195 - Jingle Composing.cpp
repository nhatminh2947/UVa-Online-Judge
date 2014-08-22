//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 12195 - Jingle Composing
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
	freopen("12195 - Jingle Composing.INP","r",stdin);
	freopen("12195 - Jingle Composing.OUT","w",stdout);
	string s;
	while(cin >> s)
	{
		if(s == "*")
			break;
		
		s.erase(s.begin());
		
		int sz = s.size();
		int c = 0;
		
		int cnt[150];
		fill(cnt,cnt+140,0);
		for(int i = 0 ; i < sz ; i++)
		{
			if(s[i] == '/')
			{
				if(cnt['X'] % 2 == 0)
				{
					cnt['T'] += cnt['X'] / 2;
					if(cnt['T'] % 2 == 0)
					{
						cnt['S'] += cnt['T'] / 2;
						if(cnt['S'] % 2 == 0)
						{
							cnt['E'] += cnt['S'] / 2;
							if(cnt['E'] % 2 == 0)
							{
								cnt['Q'] += cnt['E'] / 2;
								if(cnt['Q'] % 2 == 0)
								{
									cnt['H'] += cnt['Q'] / 2;
									if(cnt['H'] % 2 == 0)
									{
										cnt['W'] += cnt['H'] / 2;
										if(cnt['W'] == 1)
											c++;
									}
								}
							}
						}
					}
				}
				
				fill(cnt,cnt+140,0);
			}
			else cnt[s[i]]++;
		}
		
		printf("%d\n",c);
	}
	return 0;
}

