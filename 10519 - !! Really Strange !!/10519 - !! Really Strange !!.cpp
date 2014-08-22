//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10519 - !! Really Strange !!
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

class BigNum
{
	string n;
	public:
		BigNum()
		{
			n = "";
		}
		
		friend ostream &operator << (ostream &os, BigNum &a)
		{
			os << a.n;
			return os;
		}
		
		friend istream &operator >> (istream &is, BigNum &a)
		{
			is >> a.n;
			return is;
		}
		
		BigNum normalize(BigNum a)
		{
			while(a.n[0] == '0')
				a.n.erase(a.n.begin());
			if(a.n.size() == 0)
				a.n += '0';
			return a;
		}
		
		BigNum operator + (BigNum a)
		{
			int i = n.size()-1;
			int j = a.n.size()-1;
			
			int r = 0;
			BigNum res;
			
			while(i != -1 && j != -1)
			{
				int tmp = (n[i] - '0') + (a.n[j] - '0') + r;
				r = tmp/10;
				res.n = char(tmp%10 + '0') + res.n;
				
				i--;
				j--;
			}
			
			while(i != -1)
				res.n = n[i--] + res.n;
			
			while(j != -1)
				res.n = a.n[j--] + res.n;
			
			return res;
		}
		
		BigNum operator * (BigNum a)
		{
			BigNum res;
			int sz_n = n.size();
			int sz_a = a.n.size();
			int lim = sz_n + sz_a - 1;
			for(int i = 0 ; i < lim ; i++)
				res.n += '0';
			
			int r = 0;
			for(int i = sz_n-1 ; i >= 0 ; i--)
			{
				for(int j  = sz_a-1 ; j >= 0 ; j--)
				{
					int tmp = (n[i]-'0') * (a.n[j]-'0');
					int k = res.n[i+j] - '0';
					k += (tmp+r);
					res.n[i+j] = (k%10) + '0';
					r = k/10;
				}
				if(r && i)
				{
					res.n[i-1] += r;
					r = 0;
				}
			}
			
			if(r)
				res.n = char(r+'0') + res.n;
			
			return normalize(res);
		}
		
		BigNum operator - (BigNum a)
		{
			int i = n.size()-1;
			int j = a.n.size()-1;
			
			BigNum res;
			int r = 0;
			while(i != -1 && j != -1)
			{
				if(n[i] >= a.n[j]+r)
				{
					int tmp = (n[i] - '0') - (a.n[j] - '0') - r;
					res.n = char(tmp + '0') + res.n;
					r = 0;
				}
				else
				{
					int tmp = 10 + (n[i] - '0') - (a.n[j] - '0') - r;
					res.n = char(tmp + '0') + res.n;
					r = 1;
				}
				
				i--;
				j--;
			}
			
			while(i != -1)
			{
				if((n[i]-'0') >= r)
				{
					int tmp = (n[i] - '0') - r;
					res.n = char(tmp + '0') + res.n;
					r = 0;
				}
				else
				{
					int tmp = 10 + (n[i] - '0') - r;
					res.n = char(tmp + '0') + res.n;
					r = 1;
				}
				
				i--;
			}
			
			return normalize(res);
		}
		
		BigNum convert(int a)
		{
			BigNum res;
			while(a)
			{
				res.n = char(a%10 + '0') + res.n;
				a /= 10;
			}
					
			return res;
		}
		
		bool operator == (string a)
		{
			return n == a;
		}
};

int main()
{
	freopen("10519 - !! Really Strange !!.INP","r",stdin);
	freopen("10519 - !! Really Strange !!.OUT","w",stdout);
	BigNum n;
	while(cin >> n)
	{
		if(n == "0")
		{
			cout << 1 << endl;
			continue;
		}
		BigNum m = n * n;
		m = m - n;
		BigNum two;
		two = two.convert(2);
		
		m = m + two;
		
		cout << m << endl;
	}
	return 0;
}

