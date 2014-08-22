//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 497 - Strategic Defense Initiative
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
#define maxN 100000
#define INF 1000111222

using namespace std;

int L[maxN+5],a[maxN+5],StartOf[maxN+5],T[maxN+5];
int n,m;

int bSearch(int i)
{
    int lo = 1;
    int hi = m;
    int mid;
    int res;
    while(lo <= hi)
    {
        mid = (lo+hi)/2;
        if(a[i] < a[StartOf[mid]])
        {
            res = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    //DEBUG(res);
    return StartOf[res];
}

void LIS()
{
    a[0] = -INF;
    a[n+1] = INF;
    StartOf[1] = n+1;
    L[n+1] = 1;
    m = 1;
    for(int i = n ; i >= 0 ; i--)
    {
        //DEBUG(i);
        int p = bSearch(i);
        //DEBUG(p);
        L[i] = L[p] + 1;
        if(L[i] > m)
        {
            m = L[i];
            StartOf[m] = i;
        }
        else if(a[StartOf[L[i]]] < a[i])
            StartOf[L[i]] = i;
        T[i] = p;
        //DEBUG(T[i]);
    }
    
}

int main()
{
	freopen("497 - Strategic Defense Initiative.INP","r",stdin);
	freopen("497 - Strategic Defense Initiative.OUT","w",stdout);
	
	int tcs;
	scanf(" %d ",&tcs);
    char s[100];
	for(int t = 0 ; t < tcs ; t++)
	{
	    n = 0;
	    while(gets(s))
	    {
	        //DEBUG(s);
	        if(s[0] == '\0')
                break;
            sscanf(s," %d ",&a[++n]);
	    }
	    LIS();
	    int p = T[0];
	    if(t) printf("\n");
	    printf("Max hits: %d\n",L[0]-2);
	    while(p != n+1)
	    {
	        //DEBUG(p);
	        printf("%d\n",a[p]);
	        p = T[p];
	    }
	}

	return 0;
}

