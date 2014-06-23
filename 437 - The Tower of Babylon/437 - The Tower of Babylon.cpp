//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 437 - The Tower of Babylon
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
#define int64 long long
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

class block
{
    public:
        int x,y,t;
        block();
        block(int a, int b, int c)
        {
            x = a;
            y = b;
            t = c;
        }
};

int n;
vector<block> b;
int L[10000];

bool cmp(block a, block b)
{
    if(a.x == b.x)
        return a.y > b.y;
    return a.x > b.x;
}

int LIS()
{
    int ans = -INF;
    int sz = b.size();
    for(int i = 0 ; i < sz ; i++)
    {
        L[i] = b[i].t;
        //DEBUG(b[i].x);
        //DEBUG(b[i].y);
        //DEBUG(b[i].t);
        for(int j = 0 ; j < i ; j++)
        {
            //printf("=="); DEBUG(b[j].x);
            //printf("=="); DEBUG(b[j].y);
            //printf("=="); DEBUG(b[j].t);
            if((b[i].x < b[j].x && b[i].y < b[j].y) || (b[i].x < b[j].y && b[i].y < b[j].x))
            {
                L[i] = max(L[i],b[i].t+L[j]);
            }
        }
        ans = max(ans,L[i]);
        //DEBUG(ans);
        //printf("\n");
    }
    
    return ans;
}

int main()
{
	freopen("437 - The Tower of Babylon.INP","r",stdin);
	freopen("437 - The Tower of Babylon.OUT","w",stdout);
	int tmp,tcs = 1;
	while(scanf(" %d ",&n) && n)
	{
	    b.clear();
	    for(int i = 0 ; i < n ; i++)
	    {
	        int x,y,z;
	        scanf(" %d %d %d ",&x,&y,&z);
	        b.pb(block(x,y,z));
	        b.pb(block(x,z,y));
	        b.pb(block(y,x,z));
	        b.pb(block(y,z,x));
	        b.pb(block(z,y,x));
	        b.pb(block(z,x,y));
	    }
	    sort(b.begin(),b.end(),cmp);
	    
        printf("Case %d: maximum height = %d\n",tcs++,LIS());
	}

	return 0;
}

