//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 12482
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

string s[1005];

int main()
{
	freopen("12482.INP","r",stdin);
	freopen("12482.OUT","w",stdout);
	int n,l,c;
	while(scanf(" %d %d %d ",&n,&l,&c) == 3)
	{
		for(int i = 0 ; i < n ; i++)
			cin >> s[i];
		
		int len = 0;
		int line = 0;
		int page = 0;
		
		for(int i = 0 ; i < n ; i++)
		{
			len += s[i].size();
			if(len > c)
			{
				len = 0;
				line++;
				i--;
				continue;
			}
			len++;
		}
		
		if(len > 0)
			line++;
		page = line / l;
		line %= l;
		if(line > 0)
			page++;
		
		cout << page << endl;
	}
	return 0;
}

