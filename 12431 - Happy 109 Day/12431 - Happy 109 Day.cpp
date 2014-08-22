//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 12431 - Happy 109 Day
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

int64 n,b,d,m;

int64 mult(int64 a, int64 b)
{
	int64 res = 0;
	while(b)
	{
		if(b & 1)
			res += a;
		if(res >= m)
			res -= m;
		
		a <<= 1;
		if(a >= m)
			a -= m;
		
		b >>= 1;
	}
	
	return res;
}

struct Matrix
{
	int64 M[5][5];
	
	Matrix()
	{
		M[1][1] = M[1][2] = M[2][1] = M[2][2] = 0;
	}
	
	Matrix Mul(Matrix a)
	{
		Matrix ans;
		for(int i = 1 ; i <= 2 ; i++)
			for(int j = 1 ; j <= 2 ; j++)
			{
				for(int k = 1 ; k <= 2 ; k++)
					ans.M[i][j] += mult(M[i][k], a.M[k][j]);
				if(ans.M[i][j] >= m)
					ans.M[i][j] -= m;
			}
		
		return ans;
	}
	
	Matrix Pow(int64 n)
	{
		Matrix res;
		Matrix p;
		p = *this;
		res.M[1][1] = 1; res.M[1][2] = 0;
		res.M[2][1] = 0; res.M[2][2] = 1;
		
		while(n)
		{
			if(n & 1)
				res = res.Mul(p);
			p = p.Mul(p);
			
			n >>= 1;
		}
		return res;
	}
};

Matrix X;

int main()
{
	freopen("12431 - Happy 109 Day.INP","r",stdin);
	freopen("12431 - Happy 109 Day.OUT","w",stdout);
	X.M[1][2] = 1;
	X.M[2][1] = 0;
	X.M[2][2] = 1;
	int tcs;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		scanf(" %lld %lld %lld %lld ",&n,&b,&d,&m);
		X.M[1][1] = b;
		
		Matrix Y;
		Y = X.Pow(n);
		
		printf("Case %d: %lld\n",t,mult(d,Y.M[1][2]));
	}
	return 0;
}

