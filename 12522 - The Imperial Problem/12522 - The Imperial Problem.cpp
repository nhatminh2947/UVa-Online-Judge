//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 12522 - The Imperial Problem
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

string s;
int val[200];
map<int,string> ch;

void init()
{
	val['I'] = 1;
	val['V'] = 5;
	val['X'] = 10;
	val['L'] = 50;
	val['C'] = 100;
	val['D'] = 500;
	val['M'] = 1000;
	
	ch[1] = "I";
	ch[2] = "II";
	ch[3] = "III";
	ch[4] = "IV";
	ch[5] = "V";
	ch[6] = "VI";
	ch[7] = "VII";
	ch[8] = "VIII";
	ch[9] = "IX";
	
	ch[10] = "X";
	ch[20] = "XX";
	ch[30] = "XXX";
	ch[40] = "XL";
	ch[50] = "L";
	ch[60] = "LX";
	ch[70] = "LXX";
	ch[80] = "LXXX";
	ch[90] = "XC";
	
	ch[100] = "C";
	ch[200] = "CC";
	ch[300] = "CCC";
	ch[400] = "CD";
	ch[500] = "D";
	ch[600] = "DC";
	ch[700] = "DCC";
	ch[800] = "DCCC";
	ch[900] = "CM";
	
	ch[1000] = "M";
	ch[2000] = "MM";
	ch[3000] = "MMM";
}

int number(string s)
{
	int n = 0;
	int sz = s.size();
	for(int i = 0 ; i < sz ; i++)
	{
		if(i != sz-1)
		{
			if(s[i] == 'I' && s[i+1] == 'V')
			{
				n += 4;
				i++;
			}
			else if(s[i] == 'I' && s[i+1] == 'X')
			{
				n += 9;
				i++;
			}
			else if(s[i] == 'X' && s[i+1] == 'L')
			{
				n += 40;
				i++;
			}
			else if(s[i] == 'X' && s[i+1] == 'C')
			{
				n += 90;
				i++;
			}
			else if(s[i] == 'C' && s[i+1] == 'D')
			{
				n += 400;
				i++;
			}
			else if(s[i] == 'C' && s[i+1] == 'M')
			{
				n += 900;
				i++;
			}
			else n += val[s[i]];
		}
		else n += val[s[i]];
	}
	
	return n;
}

string roman(int n)
{
	string s = "";
	int p = 1;
	while(n)
	{
		s = ch[(n%10)*p] + s;
		p*=10;
		n/=10;
	}
	
	return s;
}

int main()
{
	freopen("12522 - The Imperial Problem.INP","r",stdin);
	freopen("12522 - The Imperial Problem.OUT","w",stdout);
	init();
	while(cin >> s)
	{
		if(s == "*")
			break;
		
		int n = number(s);
		//cout << n << endl;
		string r = roman(n);
		//cout << s << endl;
		//cout << r << endl;
		
		int szs = s.size();
		int szr = r.size();
		
		int m = -INF;
		for(int i = 0 ; i < szs ; i++)
		{
			int cnt = 0;
			for(int j = 0 ; j < szr ; j++)
				if(s[i+j] == r[j])
					cnt++;
			
			m = max(cnt,m);
		}
		
		int c = szr - m;
		int e = szs - szr + c;
		printf("%d %d\n",e,c);
	}
	return 0;
}

