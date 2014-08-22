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
	//freopen(".INP","r",stdin);
	freopen("test.OUT","w",stdout);
	printf("10\n");
	printf("25\n");
	for(int i = 0 ; i < 25 ; i++)
	{
		int k = rand()%10 + 1;
		int l = rand()%10 + 1;
		while(l == k)
			l = rand()%10 + 1;
		printf("%d %d %d\n",l,k,rand()%1000+1);
	}
	return 0;
}

