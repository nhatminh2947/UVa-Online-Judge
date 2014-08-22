//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10922 - 2 the 9s
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

int deg;

bool multi(string n)
{
	deg = 1;
	int sz = n.size();
	int tmp = 0;
	for(int i = 0 ; i < sz ; i++)
		tmp += (n[i] - '0');
	
	while(tmp > 9)
	{
		int k = 0;
		while(tmp)
		{
			k += tmp%10;
			tmp /= 10;
		}
		tmp = k;
		deg++;
	}
	
	if(tmp % 9)
		return false;
	return true;
}

int main()
{
	freopen("10922 - 2 the 9s.INP","r",stdin);
	freopen("10922 - 2 the 9s.OUT","w",stdout);
	string n;
	while(cin >> n)
	{
		if(n == "0")
			break;
		
		cout << n;
		if(multi(n))
			printf(" is a multiple of 9 and has 9-degree %d.\n",deg);
		else puts(" is not a multiple of 9.");
	}
	
	return 0;
}

