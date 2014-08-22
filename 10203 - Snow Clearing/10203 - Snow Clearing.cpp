//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10203 - Snow Clearing
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

struct point
{
    double x,y;
};

double dist(point a, point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main()
{
	freopen("10203 - Snow Clearing.INP","r",stdin);
	freopen("10203 - Snow Clearing.OUT","w",stdout);
	int tcs;
	scanf(" %d ",&tcs);
	for(int t = 0 ; t < tcs ; t++)
	{
	    if(t) printf("\n");
	    double x,y;
	    scanf(" %lf %lf ",&x,&y);
	    double tm = 0;
	    char s[1000];
	    while(gets(s))
	    {
	        if(s[0] == '\0')
                break;
            point a,b;
            sscanf(s,"%lf %lf %lf %lf",&a.x,&a.y,&b.x,&b.y);
            double d = dist(a,b);
            tm += d/10000;
	    }
	    int m = (int)(tm * 60 + 0.5);
        printf("%d:%02d\n",m/60,m%60);
	}
	

	return 0;
}

