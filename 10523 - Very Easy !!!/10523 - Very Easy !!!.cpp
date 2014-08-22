//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10523 - Very Easy !!!
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

class BigNum()
{
	string n;
	public:
		BigNum()
		{
			n = "";
		}
		
		BigNum operator + (BigNum a)
		{
			int r = 0;
			int sz_n = n.size() - 1;
			int sz_a = a.n.size() - 1;
			BigNum res;
			while(sz_n != -1 && sz_a != -1)
			{
				int tmp = (n[sz_n] - '0') + (a.n[sz_a] - '0');
				r = tmp/10;
				res.n = char(tmp%10 + '0') + res.n;
				sz_n--;
				sz_a--;
			}
			
			while(sz_n != -1)
			{
				res.n = n[sz_n] + res.n;
				sz_n--;
			}
			
			while(sz_a != -1)
			{
				res.n = a.n[sz_a] + res.n;
				sz_a--;
			}
			
			return res;
		}
		
		BigNum operator * (BigNum a)
		{
			
		}
}

int main()
{
	freopen("10523 - Very Easy !!!.INP","r",stdin);
	freopen("10523 - Very Easy !!!.OUT","w",stdout);
	
	return 0;
}

