//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10596 - Morning Walk
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
#define i64 long long
#define u64 unsigned long long
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define maxN 123456
#define INF 1000111222

using namespace std;

inline int number()
{
    char s[30];
    scanf(" %s ",&s);
    int n = 0;
    int sz = strlen(s);
    for(int i = 0 ; i < sz ; i++)
        n = n*10 + (s[i] - '0');
    return n;
}

int main()
{
	freopen("10596 - Morning Walk.INP","r",stdin);
	freopen("10596 - Morning Walk.OUT","w",stdout);
	int d[205];
	int n,r;
	while(scanf(" %d %d ",&n,&r) == 2)
	{
	    for(int i = 0 ; i < n ; i++)
            d[i] = 0;
	    for(int i = 0 ; i < r ; i++)
        {
            int u,v;
            scanf(" %d %d ",&u,&v);
            d[u]++;
            d[v]++;
        }
        
        bool pos = true;
        for(int i = 0 ; i < n && pos; i++)
            if(d[i] % 2 || !d[i])
                pos = false;
        if(pos)
            printf("Possible\n");
        else printf("Not Possible\n");
	}

	return 0;
}

