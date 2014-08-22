//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10929 - You can say 11
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

int Mod(string s)
{
	int d = 0;
	int sz = s.size();
	for(int i = 0 ; i < sz ; i++)
		d = (d*10 + s[i] - '0') % 11;
	
	return d;
}

int main()
{
	freopen("10929 - You can say 11.INP","r",stdin);
	freopen("10929 - You can say 11.OUT","w",stdout);
	string s;
	while(cin >> s)
	{
		if(s == "0")
			break;
		cout << s;
		if(Mod(s) == 0)
			puts(" is a multiple of 11.");
		else puts(" is not a multiple of 11.");
	}
	return 0;
}

